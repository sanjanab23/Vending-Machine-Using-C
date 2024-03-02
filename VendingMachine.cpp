#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    int quantity;
    float price;
} Item;

void displayMenu(Item items[], int cart[], int itemCount) {
    printf("Welcome to the Vending Machine!\n");
    printf("Available Items:\n");
    printf("========================================\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d. %-15sQuantity: %d\tPrice: ?%.2f\n", i+1, items[i].name, items[i].quantity - cart[i], items[i].price);
    }
    printf("========================================\n");
}

void addItemToCart(Item items[], int index, int cart[]) {
    int quantity;
    printf("Enter quantity to add to cart: ");
    scanf("%d", &quantity);
    if (quantity > items[index].quantity - cart[index]) {
        printf("Not enough quantity available.\n");
    } else {
        cart[index] += quantity;
        printf("Item %s added to cart.\n", items[index].name);
    }
}

void removeItemFromCart(Item items[], int index, int cart[]) {
    int quantity;
    printf("Enter quantity to remove from cart: ");
    scanf("%d", &quantity);
    if (quantity > cart[index]) {
        printf("Not enough quantity in cart.\n");
    } else {
        cart[index] -= quantity;
        printf("Item %s removed from cart.\n", items[index].name);
    }
}

float calculateTotal(Item items[], int cart[], int itemCount) {
    float total = 0.0;
    for (int i = 0; i < itemCount; i++) {
        total += cart[i] * items[i].price;
    }
    return total;
}

int main() {
    Item items[] = {
        {"Dairy Milk", 10, 20.50},
        {"KitKat", 15, 35.75},
        {"Lays (Original)", 20, 25.25},
        {"Lays (Barbecue)", 20, 30.00},
        {"Coke", 25, 45.60},
        {"Mountain Dew", 20, 40.75},
        {"Biscuit (Digestive)", 30, 22.30},
        {"Biscuit (Chocolate Chip)", 30, 28.90}
    };

    int itemCount = sizeof(items) / sizeof(items[0]);
    int cart[itemCount];
    for (int i = 0; i < itemCount; i++) {
        cart[i] = 0;
    }

    int choice;

    do {
        displayMenu(items, cart, itemCount);
        printf("\nOptions:\n");
        printf("1. Add Item to Cart\n");
        printf("2. Remove Item from Cart\n");
        printf("3. View Cart\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int index;
                printf("Enter the item number to add to cart: ");
                scanf("%d", &index);
                if (index >= 1 && index <= itemCount) {
                    addItemToCart(items, index - 1, cart);
                } else {
                    printf("Invalid item number.\n");
                }
                break;
            }
            case 2: {
                int index;
                printf("Enter the item number to remove from cart: ");
                scanf("%d", &index);
                if (index >= 1 && index <= itemCount) {
                    removeItemFromCart(items, index - 1, cart);
                } else {
                    printf("Invalid item number.\n");
                }
                break;
            }
            case 3:
                printf("Items in Cart:\n");
                printf("========================================\n");
                for (int i = 0; i < itemCount; i++) {
                    if (cart[i] > 0) {
                        printf("%s - Quantity: %d\n", items[i].name, cart[i]);
                    }
                }
                printf("========================================\n");
                printf("Total amount in cart: ?%.2f\n", calculateTotal(items, cart, itemCount));
                break;
            case 0:
                printf("Thank you for using the vending machine!\n");
                printf("Total amount to be paid: ?%.2f\n", calculateTotal(items, cart, itemCount));
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
