#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct List
{
	char *pw;
	struct List *next;
} *lst;

lst create(){
	lst p = malloc(sizeof(struct List));
	p -> next = NULL;
	return p;
}

void push_back(lst *L, char *w){
	lst q = create();
	q -> pw = w;
	if(*L == NULL)
	{
		*L = create();
		*L = q;
		return;
	}
	lst t = *L;
	while(t -> next != NULL)
		t = t -> next;
	t -> next = q;
	t = q;
}

void printList(lst L){
	puts("");
	while(L != NULL)
	{
		printf("%s ", L -> pw);
		L = L-> next;
	}
}

void repW(lst *L){
	lst t1, t2;
	t1 = *L;
	while(t1 != NULL && t1 -> next != NULL)
	{
		t2 = t1;
		while(t2 -> next!= NULL)
		{
			if(!strcmp(t1 -> pw, t2 -> next -> pw))
			{
				lst temp = t2 -> next;
				t2 -> next = temp -> next;
				free(temp);
			}
			else
				t2 = t2 -> next;
		}
		t1 = t1 -> next;
	}
}

int main()
{
	char *buf, ch;
	enum {OUT, IN};
	int state = OUT, len;
	lst L = NULL;

	printf("Enter a string: ");
	int i = 0, l = 1;
	buf = malloc(sizeof(char));
	while((ch = getchar()) != '\n')
	{
		buf = realloc(buf, (l += 1) * sizeof(char));
		buf[i++] = ch;
	}
	len = strlen(buf);

	for(i = 0; i < len; i++)
	{
		ch = buf[i];
		if(state == OUT && ch != ' ')
		{
			state = IN;
			push_back(&L, &buf[i]);
		}
		else if(state == IN && ch == ' ')
		{
			state = OUT;
			buf[i] = '\0';
		}
	}
	repW(&L);
	printList(L);
	return 0;
}

