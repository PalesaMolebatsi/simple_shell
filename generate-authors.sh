#!/usr/bin/env bash
set -e


current_dir="$(dirname "$(readlink -f "$BASH_SOURCE")")/."


# see also ".mailmap" for how email addresses and names are deduplicated


{
	cat <<- 'EOF'
# This file lists all individuals having contributed content to the repository
# For how it is generated, see `generate-authors.sh`.


	EOF
	echo
	git log --format='%aN <%aE>' | LC_ALL=C.UTF-8 sort -uf


} > AUTHORS_FILE
