struct Element3 {
	char Nome[20];
	char *copia[20];

};

struct Cell3 {
	struct Element3 Item;
	struct Cell3 *Prox;
};

struct TStack {
	struct Cell3 *Bottom;
	struct Cell3 *Top;
	int Size;
};

void InitializeStack(struct TStack *Stack) {
	(*Stack).Top = NULL;
	(*Stack).Bottom = (*Stack).Top;
	(*Stack).Size = 0;
}

int Empty(struct TStack Stack) {
	return (Stack.Top == NULL);
}

void Push(struct Element3 E, struct TStack *Stack) {
    struct Cell3 *Aux;
	Aux = (struct Cell3*) malloc(sizeof(struct Cell3));
	(*Aux).Item = E;
    (*Aux).Prox = (*Stack).Top;
	(*Stack).Top = Aux;
	(*Stack).Size++;
	if ((*Stack).Size == 1)
	   (*Stack).Bottom = (*Stack).Top;
}

void Pop(struct Element3 *E, struct TStack *Stack) {
	if (Empty((*Stack)))
		printf("");
	else {
		struct Cell3 *Aux;
		Aux = (*Stack).Top;
		(*Stack).Top = (*Aux).Prox;
		*E = (*Aux).Item;
		free(Aux);
		(*Stack).Size--;
		if ((*Stack).Size == 0)
	       (*Stack).Bottom = (*Stack).Top;
    }
}

int LenghtStack(struct TStack Stack) {
    return Stack.Size;
}


