#include <iostream>
#include <iomanip> // setprecision
#include <vector>
#include <memory> // unique memory
#include <utility>

#include "GroceryItem.hpp"




int main()
 {
  std:: cout << std::showpoint << std::fixed << std:: setprecision( 2 )  // Remember: These are "sticky" settings - they remain in effect for the entire program until specifically changed
             << "Welcome to Kroger. Place your grocery items into your shopping cart by entering each item's information.\n"
             << " enclose string entries in quotes, separate fields with comas\n"
             << " for example: \"00016000306707\", \"Betty Crocker Double Chocolate Chunk Cookie Mix\", 17.19\n"
             << " Enter CTL-Z (Windows) or CTL-D (Linux) to quit\n\n";

  // Create an empty collection of pointer to grocery items
 std::vector<std::unique_ptr<GroceryItem>> shoppingCart;

// Prompt for, and then for each item input by the user read the UPC code until end of file
 GroceryItem item;

 while( std::cout << "Enter UPC, Product Band, Product Name, and Price\n", std::cin>> item  )
 {
  shoppingCart.emplace_back( std::make_unique<GroceryItem>( std::move( item ) ) );
  std::cout << "Item added to shopping cart: " << *shoppingCart.back() << "\n\n";
 }
 

 //All items are now in the shopping cart so display them in reverse order
 // Use constant iterators to avoid changing the contents of the things pointer to, and use iterators to walk backwards

 std::cout << "\n\nHere is an itemized list of the items in your shopping cart: \n";

while(! shoppingCart.empty())
{
  std::cout << *shoppingCart.back();
  shoppingCart.pop_back();
}
for( auto i = shoppingCart.crbegin(); i < shoppingCart.crbegin(); ++i){
  std::cout<< **i << '\n';
}
  return 0;
}
