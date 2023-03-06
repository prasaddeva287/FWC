typedef struct Node {
    int value;
    int row;
    int col;
    struct Node* next;
} Node;



Node* createNode(int value, int row, int col) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->row = row;
    newNode->col = col;
    newNode->next = NULL;
    return newNode;
}

void insert_node(Node **head, int row, int col, int val) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->row = row;
    new_node->col = col;
    new_node->value = val;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
}
// Function to load a matrix from .dat files

Node* loadtxt(char *str) {
    FILE *fp = fopen(str, "r");
    Node* head = NULL;
    Node* currentRow = NULL;

    int numRows = 2;
    int numCols = 1;

    // Loop through each row
    for (int i = 0; i < numRows; i++) {
        Node* newRow = NULL;
        Node* currentCol = NULL;

        // Loop through each column in the current row
        for (int j = 0; j < numCols; j++) {
            int value;
            fscanf(fp,"%d", &value);

            if (value != 0) {
                Node* newNode = createNode(value, i, j);
                if (newRow == NULL) {
                    newRow = newNode;
                    currentCol = newNode;
                } else {
                    currentCol->next = newNode;
                    currentCol = newNode;
                }
            }
        }

        if (newRow != NULL) {
            if (head == NULL) {
                head = newRow;
                currentRow = newRow;
            } else {
                currentRow->next = newRow;
                currentRow = newRow;
            }
        }
    }
    fclose(fp);
    return head;
}



void print(Node* head) {

    int numRows = 0, numCols = 0;
    for (Node* curr = head; curr != NULL; curr = curr->next) {
        if (curr->row >= numRows) {
            numRows = curr->row + 1;
        }
        if (curr->col >= numCols) {
            numCols = curr->col + 1;
        }
    }
    if (numCols == 1) {
        numRows = 2;
    }

    // Loop through each row in the matrix
    for (int i = 0; i < numRows; i++) {
        // Loop through each column in the matrix
        for (int j = 0; j < numCols; j++) {

            Node* curr = head;
            while (curr != NULL && (curr->row < i || (curr->row == i && curr->col < j))) {
                curr = curr->next;
            }
            if (curr != NULL && curr->row == i && curr->col == j) {
                printf("%d ", curr->value);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

// Function for saving the matrix into a .dat file
void save(char *filename, Node* head, int numRows, int numCols) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Could not open file for writing.\n");
        return;
    }

    // Loop through each row
    for (int i = 0; i < numRows; i++) {
        Node* current = head;
        int j = 0;

        // Loop through each column in the current row
        while (current != NULL && current->row == i) {
            // Fill in any missing values with 0
            while (j < current->col) {
                fprintf(fp, "%d ", 0);
                j++;
            }

            // Write the value of the current node to the file
            fprintf(fp, "%d ", current->value);
            j++;
            current = current->next;
        }

        // Fill in any remaining empty columns with 0
        while (j < numCols) {
            fprintf(fp, "%d ", 0);
            j++;
        }

        // Add a newline character at the end of each row
        fprintf(fp, "\n");
    }

    fclose(fp);
}
 
//Function for the addition
Node *linalg_add(Node *a, Node *b) {
    Node *result = NULL;

    while (a != NULL && b != NULL) {
        if (a->row < b->row || (a->row == b->row && a->col < b->col)) {
            insert_node(&result, a->row, a->col, a->value);
            a = a->next;
        } else if (a->row == b->row && a->col == b->col) {
            int val = a->value + b->value;
            if (val != 0) {
                insert_node(&result, a->row, a->col, val);
            }
            a = a->next;
            b = b->next;
        } else {
            insert_node(&result, b->row, b->col, b->value);
            b = b->next;
        }
    }

    while (a != NULL) {
        insert_node(&result, a->row, a->col, a->value);
        a = a->next;
    }

    while (b != NULL) {
        insert_node(&result, b->row, b->col, b->value);
        b = b->next;
    }

   return result;
}


Node *linalg_scalar_mul(Node *a, double num) {
    Node *result = NULL;
    
    while (a != NULL) {
        double val = num * a->value;
        insert_node(&result, a->row, a->col, val);
        a = a->next;
    }
    
    return result;
}

