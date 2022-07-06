#include <iostream>
#include <vector>

//Used for test1
//Scoped enumeration holding the items for a grocery list
// The value of the enumerator could be the item code
enum class Grocery_Item {Milk = 350, Bread = 250, Apple = 132, Orange = 100};

std::ostream &operator<<(std::ostream &os, Grocery_Item grocery_Item)
{
    std::underlying_type_t<Grocery_Item> value = std::underlying_type_t<Grocery_Item>(grocery_Item);
    switch (grocery_Item)
    {
    case Grocery_Item::Milk:
        os << "Milk";
    case Grocery_Item::Bread:
        os << "Bread";
        break;
    case Grocery_Item::Apple:
        os << "Apple";
        break;
    case Grocery_Item::Orange:
        os << "Orange";
        break;
    default:
        os << "Invalid item";
        break;
    }
}

// Used for test1
// Returns a boolean depending on whether the Grocery_Item
// paramter is a valid enumerator or not
bool is_valid_grocery_item(Grocery_Item grocery_Item)
{
    switch (grocery_Item)
    {
    case Grocery_Item::Milk:
    case Grocery_Item::Bread:
    case Grocery_Item::Apple:
    case Grocery_Item::Orange:
        return true;
    default:
        return false;
    }
}

// Used for test1
// Display the grocery items in the grocery list
// Gicen a vector of Grocery_Items, this function displays
// the string representation of each item using the overloaded
// operator<< function
// This function also keeps track of how many valid and invalid items
// are in the provided vector by using the is_valid_grocery_item function
// written above
void display_grocery_list(const std::vector<Grocery_Item> &grocery_List)
{
    std::cout << "Grocery List" << "\n ===================" << std::endl;
    int invalid_item_count{0};
    int valid_item_count{0};
    for(Grocery_Item grocery_Item: grocery_List)
    {
        std::cout << grocery_Item << std::endl;
        if(is_valid_grocery_item(grocery_Item))
            valid_item_count++;
        else
            invalid_item_count++;
    }
    std::cout << "===================" << std::endl;
    std::cout << "Valid items:" << valid_item_count << std::endl;
    std::cout << "Invalid items:" << invalid_item_count << std::endl;
    std::cout << "Total items:" << valid_item_count + invalid_item_count << std::endl;
}

void test1()
{
    std::cout << "\n Test1 ===================" << std::endl;
    std::vector<Grocery_Item> shopping_list;

    shopping_list.push_back(Grocery_Item::Apple);
    shopping_list.push_back(Grocery_Item::Milk);
    shopping_list.push_back(Grocery_Item::Orange);
    
    int Helicopter {100};
    shopping_list.push_back(Grocery_Item(Helicopter));
    shopping_list.push_back(Grocery_Item(350));
    
    display_grocery_list(shopping_list);
}

int main()
{
    test1();
    std::cout << "\n";
    return 0;
}
