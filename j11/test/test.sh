#! /bin/sh

# message colors

ERROR_COLOR='1;31'         # Errors
HILITE_COLOR='1;33;4'      # Matches
INFO_COLOR='1;32'          # Information (e.g. current text, globality)
MATCHES_COLOR='37'         # Match count
PROMPT_COLOR='1;36'        # Prompt
TITLE_COLOR='1;33'         # Emphasized messages

# Determine whether we can afford attempting ANSI codes or not.

tty -s <&1 && hasTTY=true || hasTTY=false

##
# Clears the console (requires ANSI terminal) and puts the prompt
# on the top-left corner.
#
clearConsole()
{
  $hasTTY && printf "\033[2J\033[H"
}

##
# ANSI-based colored output.
#
# @param (optional) -n Prevents from final EOL.
# @param color The ANSI code for the color.  Automatically bright.
# @params The message text.
#
colorMsg()
{
  msg="$1"
  color="$2"
  padding="$3"
  $hasTTY && printf "\033[${color}m"
  if [ $padding -eq 0 ]; then
    printf "%s" "$msg"
  else
    printf "%-${padding}s" "$msg"
  fi
  $hasTTY && printf "\033[0m"
}

can_val_test=0

bin="../eval_expr"

val_ok()
{
  echo -n "no error... -> ["
  colorMsg "-n" $INFO_COLOR "OK"
  echo "]"
}

val_unknown()
{
  echo -n "unknown errors... -> ["
  colorMsg "-n" $ERROR_COLOR "KO"
  echo "]"
}

val_leak()
{
  echo -n "memory leaks... -> ["
  colorMsg "-n" $ERROR_COLOR "KO"
  echo "]"
}

test_valgrind()
{
  tmp=/tmp/val_fractio.txt
  valgrind < $2 $1 2> $tmp > /dev/null
  res1=`grep 'ERROR' $tmp | cut -d" " -f 4`
  res2=`grep 'allocs.*frees' $tmp | cut -d\  -f 3`
  res3=`grep 'allocs.*frees' $tmp | cut -d\  -f 5`
  err=0
  [ 0 -ne $res1 ] && err=1
  [ $res2 -ne $res3 ] && err=2
  [ 0 -eq $err ] && val_ok
  [ 1 -eq $err ] && val_unknown;
  [ 2 -eq $err ] && val_leak;
  rm -f $tmp
}

test_ok()
{
  colorMsg "$1" $TITLE_COLOR 70
  printf " -> ["
  colorMsg "OK" $INFO_COLOR 0
  printf "]\n"
}

test_ko()
{
  colorMsg "$1" $TITLE_COLOR 70
  printf " -> ["
  colorMsg "KO" $ERROR_COLOR 0
  printf "]\n"
}

dotest()
{
  [ $# -eq 5 ] || { echo "dotest: 5 arguments expected..."; exit 1; }
  testbin="$1"
  expression="$2"
  outbase="$3"
  expected_result="$4"
  expected_errcode="$5"
  if [ -z "$outbase" ]; then
    actual_result=$($testbin $expression)
  else
    actual_result=$($testbin $expression $outbase)
  fi
  actual_errcode="$?"
  if [ $actual_result = $expected_result ]; then
    test_ok "${expression} = ${actual_result}"
  else
    test_ko "${expression} = ${actual_result}, but ${expected_result} expected"
  fi
  if [ $actual_errcode = $expected_errcode ]; then
    test_ok "return code = ${actual_errcode}"
  else
    test_ko "return code = ${actual_errcode}, but ${expected_errcode} expected"
  fi
  #echo "==================="
  if [ 1 -eq $can_val_test ]; then
    #for i in "$input"; do
    	#test_valgrind "echo $i | $bin"
    #done
    #echo "$input"
    test_valgrind "$testbin" "$input"
  fi
    #echo "==================="
}

[ -e $bin ] || { echo "no \"$bin\" found..."; exit 1; }

echo "====================="
echo "  TESTS DE NIVEAU 1"
echo "====================="
dotest "$bin" "1" "" "1" "0"
dotest "$bin" "1+2" "" "3" "0"
dotest "$bin" "2-1" "" "1" "0"
dotest "$bin" "2*5" "" "10" "0"
dotest "$bin" "42/6" "" "7" "0"
dotest "$bin" "7/0" "" "" "1"
dotest "$bin" "7/1" "" "7" "0"
dotest "$bin" "21+7*3" "" "42" "0"
dotest "$bin" "3+3*3+4" "" "16" "0"
dotest "$bin" "2*3%5" "" "1" "0"
dotest "$bin" "3/0" "" "" "1"
dotest "$bin" "5-6/4+6*7-7/63+9*7" "" "109" "0"
dotest "$bin" "3*5--3+6" "" "24" "0"
dotest "$bin" "3*5---3+6" "" "" "2"
dotest "$bin" "-3*-5--3+-6" "" "12" "0"
dotest "$bin" "-3*-5--3+-6+" "" "" "2"
dotest "$bin" "3+(2+" "" "" "2"
dotest "$bin" "forty-two" "" "" "2"
dotest "$bin" "3i" "" "" "2"
dotest "$bin" "6/5+3/14*82" "" "1" "0"
dotest "$bin" "53/3%1+111/555" "" "0" "0"

echo "====================="
echo "  TESTS DE NIVEAU 2"
echo "====================="
dotest "$bin" "01:1" "" "1" "0"
dotest "$bin" "01:100" "" "4" "0"
dotest "$bin" "01234:4" "" "4" "0"
dotest "$bin" "x:xxxx" "" "4" "0"
dotest "$bin" "!:" "0" "" "0"
dotest "$bin" "x:-0" "" "0" "0"
dotest "$bin" "-0:" "" "0" "0"
dotest "$bin" "1:+-1:" "" "0" "0"
dotest "$bin" "ab:bba*azertyuiop:i" "" "42" "0"
dotest "$bin" "0123456789abcdef:15+7*3" "" "42" "0"
dotest "$bin" "ac:cacaca+51/1:111" "" "59" "0"
dotest "$bin" "ac:cacaca+51/1:111" "0123456789abcdef" "3b" "0"
dotest "$bin" "-edf:eeeefde/w:www" "ba" "-aaa" "0"
dotest "$bin" "-0123456789:00000018/0123456789:3" "0123456789" "-6" "0"

echo "====================="
echo "  TESTS DE NIVEAU 3"
echo "====================="
dotest "$bin" "1+2*4" "" "9" "0"
dotest "$bin" "(1+2)*4" "" "12" "0"
dotest "$bin" "7*(2+4)" "" "42" "0"
dotest "$bin" "(3+3)*(3+4)" "" "42" "0"
dotest "$bin" "2*3%5" "" "1" "0"
dotest "$bin" "5-6/4+6*7-7/63+9*7" "" "109" "0"
dotest "$bin" "(3*5)--(3+6)" "" "24" "0"
dotest "$bin" "-(-3*-5)--(-3+-6)" "" "-24" "0"
dotest "$bin" "-(-3*-5)--(-3+-6+)" "" "" "2"
dotest "$bin" "3+(2+" "" "" "2"
dotest "$bin" "(6/5+3/14)*82" "" "82" "0"
dotest "$bin" "53/3%(1+111/555)" "" "0" "0"
dotest "$bin" "-v.@:vv@.v*(x:/(40+gh:hg))" "AB" "A" "0"
dotest "$bin" "-v.@:vv@.v/(x:/(40+gh:hg))" "" "" "1"
dotest "$bin" "-v.@:vv@.v/(x::/(40+gh:hg))" "" "" "2"
dotest "$bin" "-(-3*-5)--(-3+-6)" "<" "-<<<<<<<<<<<<<<<<<<<<<<<<" "0"
dotest "$bin" "1" "<" "<" "0"
dotest "$bin" "-x:x" "" "-1" "0"
dotest "$bin" "-x:" "" "0" "0"
dotest "$bin" "-1" "<" "-<" "0"

echo "====================="
echo "  TESTS DE NIVEAU 4"
echo "====================="
dotest "$bin" "fact(0)" "" "1" "0"
dotest "$bin" "fact(1)" "" "1" "0"
dotest "$bin" "fact(2)" "" "2" "0"
dotest "$bin" "fact(3)" "" "6" "0"
dotest "$bin" "fact(4)" "" "24" "0"
dotest "$bin" "fact(5)" "" "120" "0"
dotest "$bin" "fact(6)" "" "720" "0"
dotest "$bin" "fact(7)" "" "5040" "0"
dotest "$bin" "fibo(0)" "" "0" "0"
dotest "$bin" "fibo(1)" "" "1" "0"
dotest "$bin" "fibo(2)" "" "1" "0"
dotest "$bin" "fibo(3)" "" "2" "0"
dotest "$bin" "fibo(4)" "" "3" "0"
dotest "$bin" "fibo(5)" "" "5" "0"
dotest "$bin" "fibo(6)" "" "8" "0"
dotest "$bin" "fibo(7)" "" "13" "0"
dotest "$bin" "fibo(19)" "" "4181" "0"
dotest "$bin" "pow(2,0)" "" "1" "0"
dotest "$bin" "pow(2,1)" "" "2" "0"
dotest "$bin" "pow(2,2)" "" "4" "0"
dotest "$bin" "pow(2,3)" "" "8" "0"
dotest "$bin" "pow(2,4)" "" "16" "0"
dotest "$bin" "pow(2,5)" "" "32" "0"
dotest "$bin" "pow(2,6)" "" "64" "0"
dotest "$bin" "pow(2,7)" "" "128" "0"
dotest "$bin" "pow(2,8)" "" "256" "0"
dotest "$bin" "pow(2,9)" "" "512" "0"
dotest "$bin" "pow(2,10)" "" "1024" "0"
dotest "$bin" "pow(2,11)" "" "2048" "0"
dotest "$bin" "pow(2,12)" "" "4096" "0"
dotest "$bin" "pgcd(26,15)" "" "1" "0"
dotest "$bin" "pgcd(96,36)" "" "12" "0"
dotest "$bin" "pgcd(n123456789:42,n123456789:28)" "n123456789" "14" "0"
dotest "$bin" "ppcm(15,12)" "n123456789abcdef" "3c" "0"
dotest "$bin" "-pow(2,6)" "" "-64" "0"
dotest "$bin" "-pow((5+7)/4,2+10/5)" "" "-81" "0"
dotest "$bin" "fact((2+3)*2-5)" "" "120" "0"
dotest "$bin" "53/fibo(pow(2,2))%(1+111/555)-pgcd(96,36)" "" "-12" "0"
dotest "$bin" "fact(3)/(fact(2)*fact(3-2))" "01" "11" "0"
dotest "$bin" "pow(n1234567:7,p1234:2)+pgcd(10:00111,xy:yxxyx)" "0abcdefghi" "ee" "0"
