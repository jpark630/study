#include<stdio.h>
int max;
int authorID = 0;

int length = 0;

struct users{
	char name[50];
	int phone[20];
};

struct authors{
	char name[50];
	char email[100];
	char phone[20];
	int authorid;
};

struct books{
	int bookid;
	int book_1;
	char title[50];
	int authorid;
	char subject[100];
	float price;
	int copy = 1;
};

struct books book[200];
struct authors author[200];
struct users user[200];

int au = 0;

void get_author(){
	int n, j, check, i;
	check = 0;

	printf("\nEnter the name of the author: ");
	scanf("%s", author[au].name);
	printf("Enter the email of the author: ");
	scanf("%s", author[au].email);
	printf("Enter the phone number of the author: ");
	scanf("%s", author[au].phone);
	for(j = 0; j < au; j++){
		if(author[au].phone == author[j].phone){
			check++;
		}
	}
	if(check != 3){
		author[au].authorid = au + 1;
		printf("\nThe author ID of %s is %d\n", author[au].name, au + 1);
		au++;
	}
	else if(check == 3){
		printf("The author is already existing.\n");
	}
}

void put(int i){
	int j, m, n = 0;
	printf("Enter the title of the book: ");
	scanf("%s", book[i].title);
	printf("E9nter the subject of the book: ");
	scanf("%s", book[i].subject);
	printf("Enter the price of the book: ");
	scanf("%f", &book[i].price);
	printf("Enter the author ID of the book: ");
	scanf("%d", &book[i].authorid);
	for(j = 0; j < au; j++){
		if(book[i].authorid == author[j].authorid){
			n++;
		}
	}
	if(n == 0){
		printf("The author information does not exist.\nDo you want to add?\n\nYes - 1, No - 2\n");
		scanf("%d", &m);
		if(m == 1){
			get_author();
		}
	}
}

void display_author(){
	int i, j;
	for(i = 0; i < au; i++){
		for(j = 0; j < i; j++){
			if(author[i].authorid == book[j].authorid){
				printf("The book written by author %s\n", author[i].name);
				printf("%s", book[j].title);
			}
		}
	}
}
void display();

int gostop = 1;

void add(){
	int i, j, size;
	
	
	printf("\nEnter the number of books: ");
    scanf("%d", &size);
    length += size;
    
	while(length > max){
        printf("Exceeding the limit\nEnter the number of books again: ");
        scanf("%d", &size);
	}

    for(i = length - size; i < length; i++){
        printf("Enter the book ID #%d: ", i+1);
        scanf("%d", &book[i].bookid);
        for(j = 0; j < i; j++){
	        while(book[i].bookid == book[j].bookid){
            	printf("\nThe book ID you entered is already existing\nDo you want to enter new ID?\n");
				printf("\nYES - 1\tNO - 2\n");
				scanf("%d", &gostop);
				if(gostop == 1){
					printf("Enter the book ID #%d again: ", i + 1);
					scanf("%d", &book[i].bookid);
				}
				else{
					length = length - size + i;
					break;
					}
				j = 0;
			}
		}
		if(gostop == 1) put(i);
		else break;
	}
	gostop = 1;
}
void del(){
	int id, i;
    int j = 0;
      	
	printf("Enter the book ID you want to delete: ");
    scanf("%d", &id);
    for(i = 0; ; i++){
        if(book[i].bookid == id) break;
    	j++;
    }
    for(i = j; i < length - 1; i++){
        book[i] = book[i + 1];
    }
	length--;
	display();
}

void fin(){
	int check, id, i;
		
	check = 0;
    printf("Enter the book ID you are looking for: ");
    scanf("%d", &id);
    for(i = 0; i < length; i++){
    	if(book[i].bookid == id){
        check++;
        break;
        }
    }
    if(check == 0) printf("No existing book ID");
    else printf("Existing book ID");
}
void update(){
	int id, up, i;
		
	printf("Enter the book ID you want to update: ");
    scanf("%d", &id);
    printf("Enter the updated book ID: ");
    scanf("%d", &up);
    for(i = 0; i < length; i++){
        while(up == book[i].bookid){
            printf("\nThe book ID you entered is already existing\nEnter the book ID again: ");
            scanf("%d", &up);
        }
    }
    for(i = 0; i < length; i++){
        if(book[i].bookid == id){
            book[i].bookid = up;
            put(i);
            break;
        }
    }
}
void display(){
	int i;
		
	printf("Displaying book information\n");
    for(i = 0; i < length; i++){
        printf("\nbook ID: %d\ntitle: %s\nauthor ID: %d\nsubject: %s \nprice: %.2f\n", book[i].bookid, book[i].title, book[i].authorid, book[i].subject, book[i].price);
    }
}
void display_a(){
	int i, j, size, min;
		
	for(i = 0; i < length; i++){
        book[i].book_1 = book[i].bookid;
    }
    printf("Displaying book IDs in ascending order\n");
	for(i = 1; i < length; i++){
		min = book[i].book_1;
        for(j = i; j > 0; j--){
            if(book[j - 1].book_1 > min){
            	book[j].book_1 = book[j - 1].book_1;
            	if(j == 1){
            		book[j - 1].book_1 = min;
            		break;
				}
			}
			else{
				book[j].book_1 = min;
				break;
			}
		}
    }
    for(i = 0; i < length; i++){
        printf("%d ", book[i].book_1);
	}
}
void rent (void){
	int n, i, t;
	int j = 0;
	printf("Enter the ID of the book to rent: ");
	scanf("%d", &t);
	for(i = 0; i < length; i++){
		if(book[i].bookid == t){
			if(book[i].copy == 0){
				printf("The book is not available. Do you want to reserve it?\n");
				printf("Yes - 1    No - 2\n");
				scanf("%d", &n);
				if(n == 1){
					printf("Enter your name: ");
					scanf("%s", user[j].name);
					printf("Enter your phone number: ");
					scanf("%d", &user[j].phone);
					j++;
				}
			}
			else{
				printf("Please return the book in ten days.\n");
				book[i].copy = 0;
			}
		}
	}
}
void ret(void){
	int n, i;
	printf("Enter the ID of the book to return: ");
	scanf("%d", &n);
	for(i = 0; i < length; i++){
		if(book[i].bookid == n){
			printf("Successfully returned\n");
			book[i].copy++;
		}
	}
}
int main (void){
	int n, m;
	while(1){
		printf("--------------------------------------------------\n");
		printf("1. Book Management\n2. Author Management\n3. Rent\n4. Return\n");
		printf("--------------------------------------------------\n");
		printf("Enter the number: ");
		scanf("%d", &m);
	
		if(m == 1){
			printf("------------------------------------------------\n");
	    	printf("1. Add Book ID\n2. Delete Book ID\n");
    		printf("3. Search book ID\n4. Update Book ID\n5. Display Book IDs\n6. Display Book IDs in ascending order\n7. Exit\n");
    		printf("------------------------------------------------\n");
		    printf("Enter the size of the book ID array: ");
    		scanf("%d", &max);
    
			int length = 0;   
		
			while(1){
				printf("\nEnter the number: ");
	    		scanf("%d", &n);
    			if(n == 1){
        			add();
	 			}
    			else if(n == 2){
    		    	del();
    			}
    			else if(n == 3){
        			fin();
    			}
   				else if(n == 4){
        			update();
		    	}
    			else if(n == 5){
        			display();
    			}
	    		else if(n == 6){
    	    		display_a();
    			}
    			else if(n == 7){
        			break;
    			}
			}
		}
		else if(m == 2){
			printf("--------------------------------------------------\n");
			printf("1. Add author information.\n2. Display books of the author.\n3. Exit\n");
			printf("--------------------------------------------------\n");
			while(1){
				printf("Enter the number: ");
				scanf("%d", &n);
				if(n == 1){
					get_author();
				}
				else if(n == 2){
					display_author();
				}
				else if(n == 3){
					break;
				}
			}
		}
		else if(m == 3){
			rent();
		}
		else if(m == 4){
			ret();
		}
	}
}
