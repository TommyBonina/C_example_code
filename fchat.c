#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	//Gets user information
	char *me = getenv("USER");
	char buffer[4096];
	char dest[4096]; 
	char out[4096];

	snprintf(buffer, 4096, "/bigtemp/cso1/%s.chat", me);
	//opens and reads user inbox
	File *inbox = fopen(buffer, "r");
	size_t got = fread(buffer, sizeof(char), 4096, inbox);
	
	if(got == 0) {
		puts("No new messages");
	}
	else {
		puts("Your messages: ");
		printf("%s\n", buffer);
	}

	snprintf(buffer, 4096,"/bigtemp/cso1/%s.chat", me);
	truncate(buffer, 0); //removes a message from buffer
	fclose(inbox);

	puts("Who would you like to message?");
	char *out_id = fgets(dest, 4096, stdin);
	out_id[strlen(out_id) - 1] = '\0';
	snprintf(out, 4096, "/bigtemp/cso1/%s.chat", out_id);

	puts("What would you like to say");
	//Takes in message from console
	char msg[4096];
	char *mess = fgets(msg, 4096, stdin);
	File *outbox = fopen(out, "a");
	//sends message to user on same server
	fprintf(outbox,"%s: %s", me, mess);
	fclose(outbox); 
	return 0;

}
