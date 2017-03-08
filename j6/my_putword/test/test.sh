#!/bin/sh

## colors definition
green='[01;32m'
yellow='[01;33m'
orange='[00;33m'
red='[01;31m'
endcolor='[0m'
## 

msg()
{
  padding=`echo -n "[$2]" | wc -m | tr -d [[:space:]]`
  padding=`expr 40 - ${padding}`
  [ "OK" = $2 ] && startcolor="$green"
  [ "KO" = $2 ] && startcolor="$red"
  printf "%-${padding}s   [${startcolor}%s${endcolor}]\n" "$1" "$2"
}

clean()
{
  make clean 1> /dev/null
  exit 0
}

clean_all()
{
  make distclean 1> /dev/null
  rm -f my_putword.out
  exit 0
}

usage()
{
  printf "usage: %s [options]\n" "$0"
  printf "options:\n"
  printf "\t%-15s: %s\n" "--clean" "Clean all *.o and test binaries"
  printf "\t%-15s: %s\n" "--clean-all" \
    "Clean all *.o, test binaries and output test files"
  exit 1
}

parseargs()
{
  while [ $# -gt 0 ]; do
    case "$1" in
      --clean)
      	clean
      	shift
      	;;
      --clean-all)
      	clean_all
      	shift
      	;;
      *)
      	usage
      	shift
      	;;
    esac
  done
}

test_compile()
{
  make 1> /dev/null 2>&1
  if [ 0 -eq $? ]; then
    msg 'Compilation test' "OK"
  else
    msg 'Compilation test' "KO"
  fi
}

test_my_putword()
{
  ./testbin > my_putword.out 2> /dev/null
  diff my_putword.expected my_putword.out > /dev/null 2>&1
  if [ 0 -eq $? ]; then
    msg 'Test ' "OK"
  else
    msg 'Test my_putword' "KO"
  fi
  }

parseargs $@

test_compile
test_my_putword
