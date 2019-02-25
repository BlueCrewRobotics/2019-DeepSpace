#!/bin/bash
touch tempFile
for i in src/main/cpp/*.cpp 
do 
	echo "formatting $i"
	clang-format $i | tee tempFile > /dev/null
	cat tempFile | tee $i > /dev/null
done
for i in src/main/cpp/*/*.cpp 
do 
	echo "formatting $i"
	clang-format $i | tee tempFile > /dev/null
	cat tempFile | tee $i > /dev/null
done


for i in src/main/include/*.h
do 
	echo "formatting $i"
	clang-format $i | tee tempFile > /dev/null
	cat tempFile | tee $i > /dev/null
done
for i in src/main/include/*/*.h
do 
	echo "formatting $i"
	clang-format $i | tee tempFile > /dev/null
	cat tempFile | tee $i > /dev/null
done




rm tempFile
