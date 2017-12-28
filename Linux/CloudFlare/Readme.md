cf-dns help:

Manipulate CloudFlare DNS entries.

cf-dns -h
	Show this synopsis.

cf-dns [-q|--quiet] [-c|--credentials <email>:<apikey>]
      -g|--get <subdomain> -t|--type <type>
  Print contents of all matching DNS entries of given type for a domain.

cf-dns [-q|--quiet] [-c|--credentials <email>:<apikey>]
      -u|--update <subdomain> -t|--type <type>
  Set or update contents of DNS entry of given type for a domain.
  This command assumes that there is at most one such entry.

CF_CREDENTIALS environment variable may be used instead of -c|--credentials switch.

dict-lookup help:
SYNOPSIS
Usage:
    dict-lookup [options...]

Options:
    -q, --quiet                 Disable error reporting by the script
    -h, --help                  Output a small usage guide and exit succesfully
    -d, --dictionary <DICT>     The dictionary that will be used.
                                if not specified, the env var DICTIONARY will be used.
    -w, --word <WORD>           The word to search a definition for

DESCRIPTION
    dict-lookup gets 2 parameters - a DICT and a WORD, and prints the translation of the word in the dictionary (the file).
    if no file is given the dictionary path is taken from DICTIONARY environment variable.
    DICT  is the dictionary file.
    -w|--word will appear before the word you search.
    WORD is the word to be search in the dictionary.


dict-update help:

SYNOPSIS
Usage:
    dict-update [options...]

Options:
    -q, --quiet                 Disable error reporting by the script
    -h, --help                  Output a small usage guide and exit succesfully
    -d, --dictionary <DICT>     The dictionary that will be used.
    -w, --word <WORD>           The word to search a definition for
    -t, --translation <TRAN>    The updated translation

DESCRIPTION
    dict-update gets 3 parameters - DICT, a WORD and a TRAN, and adds or updates the relevant line in the dictionary (the file).
    if no DICT is given the dictionary path is taken from DICTIONARY environment variable.
    DICT is the dictionary file.
    WORD is the word in the dictionary.
    TRAN is the translation of the word that will be added/updated to the dictionary.


