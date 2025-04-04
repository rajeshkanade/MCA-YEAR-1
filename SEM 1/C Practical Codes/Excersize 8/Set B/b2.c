#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structures for item-specific details
struct TV {
    int size;
    int type; // CRT = 1, LCD = 2, Plasma = 3
};

struct Mobile {
    int type; // GSM = 1, CDMA = 2
    int model_number;
};

struct Camera {
    int resolution;
    int model_number;
};

// Define a union to store specific item details
union ItemDetails {
    struct TV tv;
    struct Mobile mobile;
    struct Camera camera;
};

// Define the main Item structure
struct Item {
    int id;
    char company[50];
    int code; // 1-TV, 2-Mobile phones, 3-Camera
    float cost;
    union ItemDetails details; // Item-specific details
};

// Function to accept item details from the user
void acceptItems(struct Item* items, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for item %d:\n", i + 1);

        printf("ID: ");
        scanf("%d", &items[i].id);

        printf("Company: ");
        scanf("%s", items[i].company);

        printf("Code (1-TV, 2-Mobile phones, 3-Camera): ");
        scanf("%d", &items[i].code);

        printf("Cost: ");
        scanf("%f", &items[i].cost);

        // Accept specific details based on item type
        switch (items[i].code) {
            case 1: // TV
                printf("Enter TV size: ");
                scanf("%d", &items[i].details.tv.size);
                printf("Enter TV type (1-CRT, 2-LCD, 3-Plasma): ");
                scanf("%d", &items[i].details.tv.type);
                break;

            case 2: // Mobile Phone
                printf("Enter Mobile type (1-GSM, 2-CDMA): ");
                scanf("%d", &items[i].details.mobile.type);
                printf("Enter Mobile model number: ");
                scanf("%d", &items[i].details.mobile.model_number);
                break;

            case 3: // Camera
                printf("Enter Camera resolution: ");
                scanf("%d", &items[i].details.camera.resolution);
                printf("Enter Camera model number: ");
                scanf("%d", &items[i].details.camera.model_number);
                break;

            default:
                printf("Invalid code! Please try again.\n");
                i--; // Repeat the iteration for valid input
                break;
        }
    }
}

// Function to display all items
void displayAll(struct Item* items, int n) {
    printf("\nAll Items:\n");
    for (int i = 0; i < n; i++) {
        printf("\nID: %d, Company: %s, Code: %d, Cost: %.2f\n", 
               items[i].id, items[i].company, items[i].code, items[i].cost);

        // Display specific details based on item type
        switch (items[i].code) {
            case 1: // TV
                printf("TV Size: %d, TV Type: %d\n", 
                       items[i].details.tv.size, items[i].details.tv.type);
                break;

            case 2: // Mobile Phone
                printf("Mobile Type: %d, Model Number: %d\n", 
                       items[i].details.mobile.type, items[i].details.mobile.model_number);
                break;

            case 3: // Camera
                printf("Camera Resolution: %d, Model Number: %d\n", 
                       items[i].details.camera.resolution, items[i].details.camera.model_number);
                break;
        }
    }
}

// Function to search for an item by ID
void searchItem(struct Item* items, int n, int id) {
    for (int i = 0; i < n; i++) {
        if (items[i].id == id) {
            printf("\nItem found!\n");
            printf("ID: %d, Company: %s, Code: %d, Cost: %.2f\n", 
                   items[i].id, items[i].company, items[i].code, items[i].cost);
            return;
        }
    }
    printf("Item with ID %d not found.\n", id);
}

// Function to sort items by cost using Bubble Sort
void sortItemsByCost(struct Item* items, int n) {
    struct Item temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].cost > items[j + 1].cost) {
                // Swap items[j] and items[j + 1]
                temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
    printf("\nItems sorted by cost:\n");
    displayAll(items, n);
}

// Main function with a menu-driven approach
int main() {
    int n, choice, id;
    struct Item* items;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    // Dynamically allocate memory for n items
    items = (struct Item*)malloc(n * sizeof(struct Item));
    if (items == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Accept item details from the user
    acceptItems(items, n);

    // Menu-driven loop
    do {
        printf("\nMenu:\n");
        printf("1. Display All Items\n");
        printf("2. Search for Specific Item by ID\n");
        printf("3. Sort Items by Cost\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayAll(items, n);
                break;

            case 2:
                printf("Enter the ID of the item to search: ");
                scanf("%d", &id);
                searchItem(items, n, id);
                break;

            case 3:
                sortItemsByCost(items, n);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    // Free the allocated memory
    free(items);

    return 0;
}
