#katie pan
#assignment 7 - lecarchive.sh
#does everything a makefile does, but in bash script

#!/bin/bash

#if user types lecarchive.sh clean, this function runs and removed pdfs and archives
if [[ $1 =  "clean" ]];
then
    rm -f *.pdf lectures.tar.gz

else
    #all ppt files
    PPTFILES=`ls *.ppt | cut -f 1 -d '.'`

    #change ppt files to pdf using ppttopdf function
    for f in ${PPTFILES} ; do

        #check if pdf exists
        if [[ ! -f ${f}.pdf ]];
        then
        /home/cs352/summer16/a7/ppttopdf ${f}.ppt

        #makes new directory (only if it timestamp isn't updated)
        mkdir -p www

        PPT=`ls *.ppt`
        PDF=`ls *.pdf`

        #places pdffiles and pptfiles into archive
        tar -czf lectures.tar.gz ${PPT} ${PDF}

        #copies it into new subdirectory-> www
        cp lectures.tar.gz ./www

        fi

        #if file's timestamp is outdated
        timePDF=`date -r ${f}.pdf +%s`
        timePPT=`date -r ${f}.ppt +%s`

        if [[ ${timePDF} -lt ${timePPT} ]];
        then
        /home/cs352/summer16/a7/ppttopdf ${f}.ppt

        #makes new directory (only if it timestamp isn't updated)
        mkdir -p www

        PPT=`ls *.ppt`
        PDF=`ls *.pdf`

        #places pdffiles and pptfiles into archive
        tar -czf lectures.tar.gz ${PPT} ${PDF}

        #copies it into new subdirectory-> www
        cp lectures.tar.gz ./www

        fi

    done

fi
