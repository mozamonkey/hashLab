#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>   


int main() {
int n = 3;
unsigned char salt = 'xx';  
char hashPass[12];
char user[32];
char userid[32]; //this can all be simplified by storing pass in a variable but how do you do that?
char pass[12];
char newPass[12];


loginUser();

if (strlen(user) > 32) {
printf("Exceeds number of characters.");
loginUser();
}
else {
	if (strcmp(user,userid) != 0) {	
		
		loginPass();							
		
		//convert password to hash value, add the salt value and store in hashPass
		append(pass, salt)
		
		SHA256_CTX context;
 		unsigned char md[SHA256_DIGEST_LENGTH];
 		 					
 		hashPass = hash(pass)
 					
 		SHA256_Init(&context);
 		SHA256_Update(&context, (unsigned char*)hashPass, length);
 		SHA256_Final(md, &context);
		
		
		//compares hash to stored hash
		
	 	while (n >= 0;) {							//the if statement below may not work properly
			n--;		
			if (strcmp(pass,hashedPass) != 0) {					
				printf("Success! You've been logged in.");
				break; //exits this if statement
			}
				if (counter == 0) {
					print("You've entered the wrong password three times. Program will now terminate.");
					exit();
			}					
			
		else {		
				userRequest();
	
				if ((strlen(userid) =< 32 && strlen(userid) >= 3) {  
				
				//store userid into the unix database cell
				
					//store into unix database	
					FILE *f = fopen("passwd.txt", "w");
					if (f == NULL)
				{
					printf("Error opening file!\n");
					exit(1);
				}
				
				/* print userid */
				const char *text = userid;
				fprintf(f, "credential %s/n", text);
				
				}
				else {
				printf("Username fails requirements! Try again.");
				userRequest();
				}
				
				passwordRequest();
				
				if (((strlen(newPass) <= 12 && strlen(newPass) >= 3) && (newPass >= 'a' && newPass <= 'z') && (newPass >= 'A' && newPass <= 'Z') && (newPass >= '0' && newPass <= '9'))
				{
					//convert password to hash value, add the salt value and store in hashPass
					
					append(pass, salt)
					SHA256_CTX context;
 					unsigned char md[SHA256_DIGEST_LENGTH];
 					
 					hashPass = hash(pass)
 					
 					SHA256_Init(&context);
 					SHA256_Update(&context, (unsigned char*)hashPass, length);
 					SHA256_Final(md, &context);
					
					//store hashPass in unix database
					
					//store into unix database	
					FILE *f = fopen("passwd.txt", "w");
					if (f == NULL)
				{
					printf("Error opening file!\n");
					exit(1);
				}
				
				/* print pass */
				const char *text = hashPass;
				fprintf(f, "%s/n", text);
		
					
				}
				else { 															//indicates special characters
					Printf("Password fails requirements! Try again.");
					passwordRequest();
				}
			}
		} 
	}
}

return 0;

}


static void passwordRequest(void) {
printf("Enter a password. Must include lowercase, uppercase, numbers but NO special characters:");
scanf("%s/n", newPass);
}

static void userRequest(void) {
printf("Enter a username. Must be less than 32 characters, greater than 3");
scanf("%s/n", userid);
}

static void loginUser(void) {
printf("Enter a username:");
scanf("%s/n", user);
}

static void loginPass(void) {
printf("Enter a password:");
scanf("%s/n", pass);
}

void append(char* s, char c) {
        int len = strlen();
        s[len] = c;
        s[len+1] = '\0';
}

void append(char *s, char c) {
        int len = strlen();
        s[len] = c;
        s[len+1] = c;
}











	