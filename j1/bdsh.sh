#!/bin/sh

## useful variables
db_file="sh.db"
tmp_file="/tmp/bdsh.tmp"
##

## helper functions
select_line()
{
  regex="^([a-zA-Z][a-zA-Z0-9_]*=[a-zA-Z0-9_ ]*:)*"
  regex="${regex}${1}"
  regex="${regex}(:[a-zA-Z][a-zA-Z0-9_]*=[a-zA-Z0-9_ ]*)*$"
  < "$db_file" awk "
    /${regex}/ {
      split(\$0, records, \":\")
      for (key in records)
        if (match(records[key], \"${regex}\"))
          print \$0
    }
  "
}

##

## functions library
usage()
{
  echo "usage: ${0} <command> <argument>"
  echo "arguments:"
  echo "  insert:  append the argument to the database"
  echo "  dump:    print out the database content"
  echo "  select:  prints out entries matching the argument (may be a regex)"
  echo "  delete:  remove entries matching the argument (may be a regex)"
  echo "  drop:    delete the whole database content"
  exit 1
}

insert_line()
{
  [ $# -eq 1 ] || usage
  echo "$1" >> "$db_file"
}

dump()
{
  [ $# -eq 0 ] || usage
  if ! [ -f "$db_file" ]; then
    echo "no database found"
    exit 1
  fi
  cat "$db_file"
}

select_and_print()
{
  [ $# -eq 1 ] || usage
  echo `select_line "$1"`
}

delete_line()
{
  [ $# -eq 1 ] || usage
  line=`select_line "$1"`
  <"$db_file" sed -e "/${line}/d" > "$tmp_file"
  mv "$tmp_file" "$db_file"
}

drop()
{
  [ $# -eq 0 ] || usage
  rm "$db_file"
  touch "$db_file"
}

##


## main program
case "$1" in
  insert)
    shift
    insert_line "$@"
    ;;
  dump)
    shift
    dump "$@"
    ;;
  select)
    shift
    select_and_print "$@"
    ;;
  delete)
    shift
    delete_line "$@"
    ;;
  drop)
    shift
    drop "$@"
    ;;
  *)
    usage
esac
exit 0
