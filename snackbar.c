// Practice using structs
// Practice writing a linear search function

/**
 * Beach Burger Shack has the following 10 items on their menu
 * Burger: $9.5
 * Vegan Burger: $11
 * Hot Dog: $5
 * Cheese Dog: $7
 * Fries: $5
 * Cheese Fries: $6
 * Cold Pressed Juice: $7
 * Cold Brew: $3
 * Water: $2
 * Soda: $2
*/


#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

// Number of menu items
// Adjust this value (10) to number of items input below
#define NUM_ITEMS 10
#define MAX_INPUT 20

// Menu itmes have item name and price
typedef struct
{
    char *item;
    float price;
}
menu_item;

// Array of menu items
menu_item menu[NUM_ITEMS];

// arrays containing products and prices to add into menu array
char *products[NUM_ITEMS] = {"Burguer", "Vegan Burguer", "Hot Dog", "Cheese Dog", "Fries", "Cheese Fries", "Cold Pressed Juice", "Cold Brew", "Water", "Soda"};
float prices[NUM_ITEMS] = {9.5, 11, 5, 7, 5, 6, 7, 3, 2, 2};

// Add items to menu
void add_items(void);

// Calculate total cost
float get_cost(char *item);

int main(void)
{
    add_items();

    printf("\nWelcome to Beach Burger Shack!\n");
    printf("Choose from the following menu to order. Press enter when done.\n\n");

    for (int i = 0; i < NUM_ITEMS; i++)
    {
        printf("%s: $%.2f\n", menu[i].item, menu[i].price);
    }
    printf("\n");

    float total = 0;
    char item[MAX_INPUT];
    while (true)
    {
        printf("Select an item to order: ");
        fgets(item, MAX_INPUT, stdin);
        
        // Remove the newline character from input
        size_t length = strlen(item);
        if (length > 0 && item[length - 1] == '\n') {
            item[length - 1] = '\0';
        }

        // If no input when prompted, finish collecting orders
        if (strlen(item) == 0)
        {
            printf("\n");
            break;
        }
        total += get_cost(item);

        // Reset item to be empty;
        for (int i = 0; i < strlen(item); i++)
        {
            item[i] = '\0';
        }
    }
    printf("Your total cost is: $%.2f\n", total);
}

// Add at least the first four items to the menu array
void add_items(void)
{
    for (int i = 0; i < NUM_ITEMS; i++)
    {
        menu[i].item = products[i];
        menu[i].price = prices[i];
    }
}

// Search through the menu array to find an item's cost
float get_cost(char *item)
{
    for (int i = 0; i < NUM_ITEMS; i++)
    {
        if (strcasecmp(item, menu[i].item) == 0)
        {
            return menu[i].price;
        }
    }
    return 0.0;
}
