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


    g++ -o ${outputexe} ${source_file}
    RESULT_SIGNAL=$?
    
    if test ${RESULT_SIGNAL} -eq 0; then
        echo "コンパイルに成功しました。"
        
        if test $# -eq 1; then
            if [ -e ${txt_file} ]; then
                echo ----------------------
                echo ${txt_file} is found
                echo ----------------------
                ./${outputexe} < ${txt_file}
            else
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






