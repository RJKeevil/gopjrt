package main

import (
	"github.com/janpfeifer/must"
	"os"
	"os/exec"
	"regexp"
	"strconv"
	"strings"
	"text/template"
)

const (
	enumsFromCGoFileName = "gen_c_enums.go"
)

var (
	reEnums = regexp.MustCompile(
		`(?m)(typedef enum \{\n([^}]+)}` + // Enum definition
			`\s+(\w+)\s*;)`) // Enum type name
	reEnumComment    = regexp.MustCompile(`^\s*(//.*)$`)
	reEnumDefinition = regexp.MustCompile(`^\s*(\w+)(\s*=\s*(\w+))?\s*,?$`)

	enumsFromCTemplate = template.Must(template.New(enumsFromCGoFileName).Parse(`
package gopjrt

/***** File generated by ./cmd/codegen, don't edit it directly. *****/

{{range .}}
// {{.Name}} is mapping of the corresponded C enum defined in pjrt_c_api.h.
type {{.Name}} int
{{$x := .Name}}
const ({{range .Entries}}
	// {{.Name}} is a 1:1 mapping of the corresponding C enum value defined in pjrt_c_api.h. {{range .Comments}}
	{{.}}{{end}}
	{{.Name}} {{$x}} = {{.Value}}
{{end}})

{{end}}
`))
)

type enumTypeInfo struct {
	Name    string
	Entries []*enumEntry
}

type enumEntry struct {
	Name     string
	Comments []string
	Value    int
}

func generateEnums(contents string) {
	var allEnums []enumTypeInfo
	for _, matches := range reEnums.FindAllStringSubmatch(contents, -1) {
		eType := enumTypeInfo{
			Name: matches[3],
		}
		var eEntry *enumEntry
		for _, line := range strings.Split(matches[2], "\n") {
			if line == "" {
				continue
			}
			if eEntry == nil {
				eEntry = &enumEntry{}
			}
			if subMatches := reEnumComment.FindStringSubmatch(line); len(subMatches) > 0 {
				eEntry.Comments = append(eEntry.Comments, subMatches[1])
				continue
			}
			subMatches := reEnumDefinition.FindStringSubmatch(line)
			if len(subMatches) == 0 {
				continue
			}
			eEntry.Name = subMatches[1]
			if v := subMatches[3]; v != "" {
				eEntry.Value = int(must.M1(strconv.ParseInt(subMatches[3], 10, 64)))
			} else {
				if len(eType.Entries) == 0 {
					eEntry.Value = 0
				} else {
					eEntry.Value = eType.Entries[len(eType.Entries)-1].Value + 1
				}
			}
			eType.Entries = append(eType.Entries, eEntry)
			eEntry = nil
		}
		allEnums = append(allEnums, eType)
	}

	f := must.M1(os.Create(enumsFromCGoFileName))
	must.M(enumsFromCTemplate.Execute(f, allEnums))
	must.M(exec.Command("gofmt", "-w", enumsFromCGoFileName).Run())
}
