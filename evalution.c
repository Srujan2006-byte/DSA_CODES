#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int id;
    char name[50];
    int copies;
    struct Book *left, *right;
};
struct Book* createBook(int id, char name[], int copies) ;
struct Book* insert(struct Book* root, int id, char name[], int copies);
struct Book* search(struct Book* root, int id);
void updateCopies(struct Book* root, int id, int newCopies);
void display(struct Book* root) ;
int main() {
    struct Book* root = NULL;
    int choice, id, copies;
    char name[50];

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Book ID: ");
                scanf("%d", &id);
                printf("Enter Book Name: ");
                scanf(" %[^\n]", name);
                printf("Enter number of copies: ");
                scanf("%d", &copies);

                root = insert(root, id, name, copies);
                printf("Book inserted successfully!\n");
                break;

            case 2: {
                printf("Enter Book ID to search: ");
                scanf("%d", &id);
                struct Book* found = search(root, id);

                if (found)
                    printf("Found: %s (%d copies)\n", found->name, found->copies);
                else
                    printf("Book not found!\n");
                break;
            }

            case 3:
                printf("Enter Book ID to update: ");
                scanf("%d", &id);
                printf("Enter new number of copies: ");
                scanf("%d", &copies);
                updateCopies(root, id, copies);
                break;

            case 4:
                printf("\nLibrary Records (Sorted):\n");
                display(root);
                break;

            case 5:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}


struct Book* createBook(int id, char name[], int copies) {
    struct Book* newNode = (struct Book*)malloc(sizeof(struct Book));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->copies = copies;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Book* insert(struct Book* root, int id, char name[], int copies) {
    if (root == NULL)
        return createBook(id, name, copies);

    if (id < root->id)
        root->left = insert(root->left, id, name, copies);
    else if (id > root->id)
        root->right = insert(root->right, id, name, copies);
    else
        root->copies += copies;

    return root;
}


struct Book* search(struct Book* root, int id) {
    if (root == NULL || root->id == id)
        return root;

    if (id < root->id)
        return search(root->left, id);
    else
        return search(root->right, id);
}


void updateCopies(struct Book* root, int id, int newCopies) {
    struct Book* temp = search(root, id);
    if (temp != NULL) {
        temp->copies = newCopies;
        printf("Updated successfully!\n");
    } else {
        printf("Book not found!\n");
    }
}
void display(struct Book* root) {
    if (root != NULL) {
        display(root->left);
        printf("ID: %d | Name: %s | Copies: %d\n",
               root->id, root->name, root->copies);
        display(root->right);
    }
}
