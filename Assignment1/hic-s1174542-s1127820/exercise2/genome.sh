filename=${1}
searchString=${2}

grep -o "${searchString}" "${filename}" | wc -l