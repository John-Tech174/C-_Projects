// File Guard
#ifndef _BAKERY_HPP_
#define _BAKERY_HPP_

// Headers
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class bakery{
public:
    // To copy a customer's order into the order list
    bakery (std::vector<std::string> &initializer){
        order_list.assign(initializer.begin(),initializer.end());
        order_status.assign(order_list.size(),"pending");
    }

    // To generate a pre-prepared list of items using the vector fill constructor
    std::vector<std::string> generatePrePreparedList (size_t item_number, std::string item_name){
        std::vector<std::string> pre_prepared(item_number,item_name);
        return pre_prepared;
    }

    // To print the first item in the order list
    void printFirstItem (void){
        std::cout << "The first item : " << order_list.front() << std::endl;
    }

    // To print the last item in the order list
    void printLastItem (void){
        std::cout << "The last item : " << order_list.back() << std::endl;
    }

    // To print the item at a given position in the order list
    void printItem (size_t position){
        std::cout << "Item at position " << position << " is : " << order_list.at(position) << std::endl;
    }

    // Add a new order to the end of the list
    void addOrder (std::string new_item){
        order_list.push_back(new_item);
        order_status.push_back("pending");
    }

    // Find and complete an in progress order  
    void completeOrder (std::string target_item){
        std::vector<std::string>::iterator target_position;
        std::vector<std::string>::iterator target_status;
        size_t target_index = 0;
        bool found = false;
        for (target_position = order_list.begin();target_position != order_list.end();++target_position){
            if(*target_position == target_item){
                found = true;
                break;
            }
            else{
                ++target_index;
            }
        }
        if(found){
            target_status = order_status.begin() + target_index;
            if(*target_status == "in progress"){
                order_list.erase(target_position);
                order_status.erase(target_status);
                std::cout << "Order completed and removed" << std::endl;
            }
            else{
                std::cerr << "Order is not in progress to be completed, please put it in progress or remove it" << std::endl;
            }
        }
        else{
            std::cerr << "The order doesn't exist in the order list to be removed please add it first" << std::endl;
        }
    }

    // Find and remove an order
    void removeOrder (std::string target_item){
        std::vector<std::string>::iterator target_position;
        std::vector<std::string>::iterator target_status;
        size_t target_index = 0;
        bool found = false;
        for (target_position = order_list.begin();target_position != order_list.end();++target_position){
            if(*target_position == target_item){
                found = true;
                break;
            }
            else{
                ++target_index;
            }
        }
        if(found){
            target_status = order_status.begin() + target_index;
            order_list.erase(target_position);
            order_status.erase(target_status);
            std::cout << "Order removed without completion" << std::endl;
        }
        else{
            std::cerr << "The order doesn't exist in the order list to be removed please add it first" << std::endl;
        }
    }

    // Making the allocated capacity equal to the used size for memory optimization
    void optimizeStorage(void){
        order_list.shrink_to_fit();
        order_status.shrink_to_fit();
    }

    // Inserting the pre-prepared item list at the beginning of the order list
    void insertPrePreparedAtBeginning (std::vector<std::string> &pre_prepared_list){
        order_list.insert(order_list.cbegin(),pre_prepared_list.begin(),pre_prepared_list.end());
        order_status.insert(order_status.begin(),pre_prepared_list.size(),"pending");
    }

    // Adding a larger catering order list to the main order list
    void insertLargeOrder (std::vector<std::string> &large_order){
        order_list.insert(order_list.cend(),large_order.begin(),large_order.end());
        order_status.insert(order_status.end(),large_order.size(),"pending");
    }

    // Print the order list size, capacity and maximum possible size
    void printSizeStats (void){
        std::cout << "Order list size : " << order_list.size() << std::endl << "Order list capacity : " << order_list.capacity()
                  << std::endl << "Order list maximum possible number of elements : " << order_list.max_size() << std::endl;
    }

    // Iterating through the order list using normal iterators
    void normalIterate (void){
        std::cout << "The order list : " << std::endl;
        for (std::vector<std::string>::iterator item = order_list.begin();item != order_list.end();++item){
            std::cout << *item << '\t';
        }
        std::cout << std::endl;
    }

    // Iterating through the order list using constant iterators
    void constantIterate (void){
        std::cout << "The order list : " << std::endl;
        for (std::vector<std::string>::const_iterator item = order_list.cbegin();item != order_list.cend();++item){
            std::cout << *item << '\t';
        }
        std::cout << std::endl;
    }

    // Iterating through the order list using reverse iterators
    void reverseIterate (void){
        std::cout << "The order list : " << std::endl;
        for (std::vector<std::string>::reverse_iterator item = order_list.rbegin();item != order_list.rend();++item){
            std::cout << *item << '\t';
        }
        std::cout << std::endl;
    }

    // Iterating through the order list using auto iterators
    // void autoIterate (void);

    // Iterate through the orders' status
    void iterateStatus (void){
        std::cout << "The status of the order list : " << std::endl;
        for (std::vector<std::string>::iterator status = order_status.begin();status != order_status.end();++status){
            std::cout << *status << '\t';
        }
        std::cout << std::endl;
    }

    // Setting the status of an order to be in progress
    void setInProgress(std::string pending_order){
        std::vector<std::string>::iterator pending_order_position;
        std::vector<std::string>::iterator pending_order_status;
        bool found = false;
        size_t index = 0;
        for(pending_order_position = order_list.begin();pending_order_position != order_list.end();++pending_order_position){
            if(*pending_order_position == pending_order){
                found = true;
                break;
            }
            else{
                ++index;
            }
        }
        if(found){
            pending_order_status = order_status.begin() + index;
            *pending_order_status = "in progress";
        }
        else{
            std::cerr << "The order is not found to have an in progress status, please add it first" << std::endl;
        }
    }

    // View the status of an order (pending or in progress)
    void viewOrderStatus(std::string order){
        std::vector<std::string>::iterator pending_order_position;
        std::vector<std::string>::iterator pending_order_status;
        bool found = false;
        size_t index = 0;
        for(pending_order_position = order_list.begin();pending_order_position != order_list.end();++pending_order_position){
            if(*pending_order_position == order){
                found = true;
                break;
            }
            else{
                ++index;
            }
        }
        if(found){
            pending_order_status = order_status.begin() + index;
            std::cout << "Order status : " << *pending_order_status << std::endl;
        }
        else{
            std::cerr << "The order is not found, please add it first" << std::endl;
        }
    }

    // Clear the order list
    void clearOrderList (void){
        order_list.clear();
        order_status.clear();
    }

    // Check if empty
    bool empty (void){
        return order_list.empty();
    }

private:
    std::vector<std::string> order_list;
    std::vector<std::string> order_status;
};

#endif
