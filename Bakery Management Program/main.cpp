// This main file is used to test some of the functions offered in the bakery class

#include "bakery.hpp"

int main()
{
    std::vector<std::string> customer_orders {"bread","cake","pie"};
    bakery bakery_obj(customer_orders);
    std::vector<std::string> fill_constructor_list = bakery_obj.generatePrePreparedList(4,"biscuit");
    bakery_obj.insertPrePreparedAtBeginning(fill_constructor_list);
    bakery_obj.constantIterate();
    bakery_obj.setInProgress("biscuit");
    bakery_obj.iterateStatus();
    bakery_obj.completeOrder("biscuit");
    bakery_obj.removeOrder("cake");
    bakery_obj.constantIterate();
    bakery_obj.viewOrderStatus("biscuit");
    bakery_obj.iterateStatus();
    bakery_obj.printSizeStats();
    bakery_obj.optimizeStorage();
    bakery_obj.printSizeStats();

    return EXIT_SUCCESS;
}
