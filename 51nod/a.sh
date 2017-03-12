#! /bin/sh
for i in $(ls);do
    type=`echo $i | sed "s/^.*\.\([a-z]*\).*$/\1/"`
    if [ "$type" = "cpp" ]; then
        clang-format $i > /tmp/51nod/$i
    fi
done
