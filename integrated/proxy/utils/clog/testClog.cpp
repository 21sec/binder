//#define CLOG_TAG "testclog"

#include <stdio.h>
#include <unistd.h>
#include "sbinder/sbinderServ.h"
#include "proxy.h"
#include "clog.h"
#include "clog_mgr.h"

#define LOG_PATH "/data/clog.txt"
#define ROTATE_FILE_SIZE 256
#define ROTATE_FILE 4

void clogontriger(const char* tag,int level,const char* log,const char *filterString,void* userdata){
	printf("tringer -------------ed !!!!!!!!!!\n");
}


void clog_testcase1(){
	TOSLOGV("TEST1:I am a baby!--V-\n");
	TOSLOGD("TEST1:I am a baby!--D-\n");
	TOSLOGI("TEST1:I am a baby!--I-\n");
	TOSLOGW("TEST1:I am a baby!--W-\n");
	TOSLOGE("TEST1:I am a baby!--E-\n");
	TOSLOGF("TEST1:I am a baby!--F-\n");
	CLOGCLI("TEST1:I am a baby!--CLI-\n");
}


void clog_testcase2(){
	//clog_startlogsave(LOG_PATH,ROTATE_FILE_SIZE,ROTATE_FILE);
	const char* fts = "r:b.by";
	void* userdata = NULL;
	clog_addsavetriger(fts,clogontriger,userdata);
	//clog_setlevel("testclog",CLOG_LOGLVL_ERROR);
	clog_testcase1();
	while(1);
	clog_removesavetriger(fts,clogontriger,userdata);
	//clog_stoplogsave();
}

/**
*  multi-process test
* 
*/

void clog_testcase3(){
	
	pid_t pid = fork();
    if (pid < 0){
		return ;
	}else if (pid ==0){ //son
		clog_testcase2();
	}else{//father
		clog_testcase2();
	}
}

void clog_testcase4(){
	clog_setlevel("testclog",CLOG_LOGLVL_INFO);
	printf("******************************\n");
	clog_testcase1();
	clog_setlevel("testclog",CLOG_LOGLVL_ERROR);
	printf("******************************\n");
	clog_testcase1();

}

/*
*mult-module print
*/
void clog_testcase5(){
	clog_setlevel("MODULE A",CLOG_LOGLVL_INFO);

	clog_printf("MODULE A",CLOG_LOGLVL_VERBOSE,     "I am a baby!--V-");
	clog_printf("MODULE A",CLOG_LOGLVL_DEBUG,     "I am a baby!--D-");
	clog_printf("MODULE A",CLOG_LOGLVL_INFO,     "I am a baby!--I-");
	clog_printf("MODULE A",CLOG_LOGLVL_WARN,     "I am a baby!--W-");
	clog_printf("MODULE A",CLOG_LOGLVL_ERROR,     "I am a baby!--E-");
	clog_printf("MODULE A",CLOG_LOGLVL_FATAL,     "I am a baby!--F-");
	clog_printf("MODULE A",CLOG_LOGLVL_CLI,     "I am a baby!--C-");
	clog_printf("MODULE A",CLOG_LOGLVL_SILENT, 	"I am a baby!--S-");


	clog_setlevel("MODULE B",CLOG_LOGLVL_WARN);
	clog_printf("MODULE B",CLOG_LOGLVL_VERBOSE,     "I am a baby!--V-");
	clog_printf("MODULE B",CLOG_LOGLVL_DEBUG,     "I am a baby!--D-");
	clog_printf("MODULE B",CLOG_LOGLVL_INFO,     "I am a baby!--I-");
	clog_printf("MODULE B",CLOG_LOGLVL_WARN,     "I am a baby!--W-");
	clog_printf("MODULE B",CLOG_LOGLVL_ERROR,     "I am a baby!--E-");
	clog_printf("MODULE B",CLOG_LOGLVL_FATAL,     "I am a baby!--F-");
	clog_printf("MODULE B",CLOG_LOGLVL_CLI,	  "I am a baby!--C-");
	clog_printf("MODULE B",CLOG_LOGLVL_SILENT,     "I am a baby!--S-");

	clog_setlevel("MODULE C",CLOG_LOGLVL_FATAL);
	clog_printf("MODULE C",CLOG_LOGLVL_VERBOSE,     "I am a baby!--V-");
	clog_printf("MODULE C",CLOG_LOGLVL_DEBUG,     "I am a baby!--D-");
	clog_printf("MODULE C",CLOG_LOGLVL_INFO,     "I am a baby!--I-");
	clog_printf("MODULE C",CLOG_LOGLVL_WARN,     "I am a baby!--W-");
	clog_printf("MODULE C",CLOG_LOGLVL_ERROR,     "I am a baby!--E-");
	clog_printf("MODULE C",CLOG_LOGLVL_FATAL,     "I am a baby!--F-");
	clog_printf("MODULE C",CLOG_LOGLVL_CLI,     "I am a baby!--C-");
	clog_printf("MODULE C",CLOG_LOGLVL_SILENT,     "I am a baby!--S-");
}


void clog_testcase6(int argc,char* argv[]){
	clog_execcmdline(argc,argv);

	clog_printf("MODULE A",CLOG_LOGLVL_VERBOSE,     "A:I am a baby!--V-");
	clog_printf("MODULE A",CLOG_LOGLVL_DEBUG,     "A:I am a baby!--D-");
	clog_printf("MODULE A",CLOG_LOGLVL_INFO,     "A:I am a baby!--I-");
	clog_printf("MODULE A",CLOG_LOGLVL_WARN,     "A:I am a baby!--W-");
	clog_printf("MODULE A",CLOG_LOGLVL_ERROR,     "A:I am a baby!--E-");
	clog_printf("MODULE A",CLOG_LOGLVL_FATAL,     "A:I am a baby!--F-");
	clog_printf("MODULE A",CLOG_LOGLVL_CLI,     "A:I am a baby!--C-");
	clog_printf("MODULE A",CLOG_LOGLVL_SILENT, 	"A:I am a baby!--S-");

	clog_printf("MODULE B",CLOG_LOGLVL_VERBOSE,     "B:I am a baby!--V-");
	clog_printf("MODULE B",CLOG_LOGLVL_DEBUG,     "B:I am a baby!--D-");
	clog_printf("MODULE B",CLOG_LOGLVL_INFO,     "B:I am a baby!--I-");
	clog_printf("MODULE B",CLOG_LOGLVL_WARN,     "B:I am a baby!--W-");
	clog_printf("MODULE B",CLOG_LOGLVL_ERROR,     "B:I am a baby!--E-");
	clog_printf("MODULE B",CLOG_LOGLVL_FATAL,     "B:I am a baby!--F-");
	clog_printf("MODULE B",CLOG_LOGLVL_CLI,	  "B:I am a baby!--C-");
	clog_printf("MODULE B",CLOG_LOGLVL_SILENT,     "B:I am a baby!--S-");

	clog_printf("MODULE C",CLOG_LOGLVL_VERBOSE,     "C:I am a baby!--V-");
	clog_printf("MODULE C",CLOG_LOGLVL_DEBUG,     "C:I am a baby!--D-");
	clog_printf("MODULE C",CLOG_LOGLVL_INFO,     "C:I am a baby!--I-");
	clog_printf("MODULE C",CLOG_LOGLVL_WARN,     "C:I am a baby!--W-");
	clog_printf("MODULE C",CLOG_LOGLVL_ERROR,     "C:I am a baby!--E-");
	clog_printf("MODULE C",CLOG_LOGLVL_FATAL,     "C:I am a baby!--F-");
	clog_printf("MODULE C",CLOG_LOGLVL_CLI,     "C:I am a baby!--C-");
	clog_printf("MODULE C",CLOG_LOGLVL_SILENT,     "C:I am a baby!--S-");

}


void clog_testcase7(){
	clog_setlevel("*ALL*",CLOG_LOGLVL_FATAL);
	
	clog_printf("MODULE A",CLOG_LOGLVL_VERBOSE,     "A:I am a baby!--V-");
	clog_printf("MODULE A",CLOG_LOGLVL_DEBUG,     "A:I am a baby!--D-");
	clog_printf("MODULE A",CLOG_LOGLVL_INFO,     "A:I am a baby!--I-");
	clog_printf("MODULE A",CLOG_LOGLVL_WARN,     "A:I am a baby!--W-");
	clog_printf("MODULE A",CLOG_LOGLVL_ERROR,     "A:I am a baby!--E-");
	clog_printf("MODULE A",CLOG_LOGLVL_FATAL,     "A:I am a baby!--F-");
	clog_printf("MODULE A",CLOG_LOGLVL_CLI,     "A:I am a baby!--C-");
	clog_printf("MODULE A",CLOG_LOGLVL_SILENT, 	"A:I am a baby!--S-");

	clog_printf("MODULE B",CLOG_LOGLVL_VERBOSE,     "B:I am a baby!--V-");
	clog_printf("MODULE B",CLOG_LOGLVL_DEBUG,     "B:I am a baby!--D-");
	clog_printf("MODULE B",CLOG_LOGLVL_INFO,     "B:I am a baby!--I-");
	clog_printf("MODULE B",CLOG_LOGLVL_WARN,     "B:I am a baby!--W-");
	clog_printf("MODULE B",CLOG_LOGLVL_ERROR,     "B:I am a baby!--E-");
	clog_printf("MODULE B",CLOG_LOGLVL_FATAL,     "B:I am a baby!--F-");
	clog_printf("MODULE B",CLOG_LOGLVL_CLI,	  "B:I am a baby!--C-");
	clog_printf("MODULE B",CLOG_LOGLVL_SILENT,     "B:I am a baby!--S-");

	clog_printf("MODULE C",CLOG_LOGLVL_VERBOSE,     "C:I am a baby!--V-");
	clog_printf("MODULE C",CLOG_LOGLVL_DEBUG,     "C:I am a baby!--D-");
	clog_printf("MODULE C",CLOG_LOGLVL_INFO,     "C:I am a baby!--I-");
	clog_printf("MODULE C",CLOG_LOGLVL_WARN,     "C:I am a baby!--W-");
	clog_printf("MODULE C",CLOG_LOGLVL_ERROR,     "C:I am a baby!--E-");
	clog_printf("MODULE C",CLOG_LOGLVL_FATAL,     "C:I am a baby!--F-");
	clog_printf("MODULE C",CLOG_LOGLVL_CLI,     "C:I am a baby!--C-");
	clog_printf("MODULE C",CLOG_LOGLVL_SILENT,     "C:I am a baby!--S-");

}


int main(int argc,char* argv[]){
	sbinder_start();
	printf("main clog begin\n");
	//printf("main clog clog_testcase2\n");

	//clog_testcase1();
	clog_testcase2();
    //clog_testcase3();
    //clog_testcase4();
    //clog_testcase5();
    //clog_testcase6(argc,argv);
	//clog_testcase7();
	printf("main clog end\n");

	return sbinder_serv();

}
/*#else
 #error Must define BINDER_SERVICE or BINDER_CLIENT
#endif*/
