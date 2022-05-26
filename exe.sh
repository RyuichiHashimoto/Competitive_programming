#!/bin/bash

outputexe="main.exe"
source_file="sample.cpp"

if test $# -eq 1 || test $# -eq 2;then
    if [ ! -e $1 ]; then
        echo "sorry, I cannot found the file: "$1 
        exit 1
    fi
    if [ ! -e $2 ]; then
        echo "sorry, I cannot found the file: "$2 
        exit 2
    fi

    source_file=$1    
    txt_file=`echo ${source_file} | rev | cut -c 4- | rev`txt
    
    echo we compile $1 file
    g++ -g -o ${outputexe} ${source_file} -std=c++17
    RESULT_SIGNAL=$?
    
    if test ${RESULT_SIGNAL} -eq 0; then
        echo "コンパイルに成功しました。"
        
        if test $# -eq 1; then
            find_flag=0
            for i in `seq 1 10`
            do
                txt_file=`echo ${source_file} | rev | cut -c 5- | rev`_${i}.txt
                if [ -e ${txt_file} ]; then
                    find_flag=1;
                    echo ----------------------
                    echo ${txt_file} is found
                    echo ----------------------
                    ./${outputexe} < ${txt_file}
                    echo 
                fi
            done
            txt_file=`echo ${source_file} | rev | cut -c 4- | rev`txt                
            if [ -e ${txt_file} ]; then                
                find_flag=1;
                echo ----------------------
                echo ${txt_file} is found
                echo ----------------------
                
                ./${outputexe} < ${txt_file}
            fi

            if test ${find_flag} -eq 0; then
                ./${outputexe}
            fi                                                 
        elif test $# -eq 2; then
            ./${outputexe} < $2
        fi
    else
        echo コンパイルに失敗しました。        
    fi




elif test $# -gt 2;then
    echo "you cannot specify more than two argument"
    exit 2
fi






