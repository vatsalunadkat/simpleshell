#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

#define MAX_WORD 10
#define MAX_CHAR 100
#define DEL " "

void remove_endOfLine(char line[]){

	int i=0;
	
	while(line[i] != '\n'){
	i++;
	}

	line[i] = '\0';
}

void read_line(char line[]){

	 char* ret = fgets(line, MAX_CHAR, stdin);

//	printf("%s", line);
//	printf("test");

	remove_endOfLine(line);

	if(strcmp(line, "exit") == 0 || ret == NULL){
		exit(0);
	}

}

int process_line(char* args[], char line[]){

	int i = 0;
	args[i] = strtok(line, " ");

	if(args[i] == NULL){
	return 1;
	}

	while(args[i] != NULL){
	i++;	
	args[i] = strtok(NULL, " ");
	}

	return 1;
}

int read_parse_line(char* args[], char line[]){
	
	read_line(line);
	
	process_line(args, line);
	return 1;
}

int main(){

	char* args[MAX_WORD];
	char line[MAX_CHAR];

	printf("%s", "\ntry_shell>");
	
	while(read_parse_line(args, line)){
	
		pid_t child_pid = fork();

		if(child_pid == 0){
			execvp(args[0], args);
		}
		else{
			waitpid(child_pid, 0);
		}

	}

	return 0;
}


/*
token = strtok(line, " ");

	if(token == NULL){

	args[0] = token;
	return 1;
	}

	while(token != NULL){

	temp[i] = token;

	piping_check(temp, pipe_args, i);

	redirction_check(temp, i);

	i++;
	token = strtok(NULL, " ");
	}

*/


/* 
void loop(void){
	
	char * line;
	char ** args;
	int status;

	do{
		printf("%s", "\nMyShell >");
		line = read();
		args = parse(line);
		status = execute(args);

		free(line);
		free(args); 
		
		}

	while(status);

}

int main(int argc, char** argv) {

	//REPL Loop
	loop();
	

	return 0;
	
}

*/
