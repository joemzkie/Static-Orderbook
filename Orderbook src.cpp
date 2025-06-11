#include <iostream>
#include <vector>
#include <algorithm>

struct Orders {
    int orderId;
    float bidPrice;
    int quantity;
};

struct Stocks{
    float askPrice1 = 100;
    float askPrice2 = 110;
    float askPrice3 = 120;
    int quantity1 = 5;
    int quantity2 = 3;
    int quantity3 = 5;
};

int ctr = 1;

void buffer(){system("pause"); system("cls");}

bool prio(const Orders& a, const Orders& b){// Sort by: price > quantity > ID
        if (a.bidPrice != b.bidPrice) return a.bidPrice > b.bidPrice;
        if (a.quantity != b.quantity) return a.quantity > b.quantity;
        return a.orderId < b.orderId;
}

void closeTrade(std::vector<Orders>& order) {
    std::sort(order.begin(), order.end(), prio); //the sorting

    Stocks s;
    float asks[] = {s.askPrice1, s.askPrice2, s.askPrice3};
    int askQty[] = {s.quantity1, s.quantity2, s.quantity3};

    for (int i = 0; i < order.size(); i++) {
        int qtyCtr = 0;  // Track how much of this order has been filled

        for (int j = 0; j < 3; j++) {
            if (qtyCtr == order[i].quantity) break;  // Fully filled

            if (order[i].bidPrice >= asks[j] && askQty[j] > 0) {
                int available = order[i].quantity - qtyCtr;
                int traded = std::min(available, askQty[j]);

                //  Print only successful trades
                std::cout << "[TRADE SUCCESS] Order ID " << order[i].orderId
                          << " bought " << traded
                          << " at price " << asks[j]
                          << " from Seller " << (char)('A' + j) << "\n";

                askQty[j] -= traded;
                qtyCtr += traded;
            }
        }

        //show unmatched quantity
        if (qtyCtr < order[i].quantity) {
            std::cout << "[UNFILLED] Order ID " << order[i].orderId
                      << " has " << (order[i].quantity - qtyCtr)
                      << " units unmatched.\n";
        }
    }

    std::cout << "\n--- Trade session ended. ---\n";
    exit(0);
}

void addOrder(std::vector<Orders>& order) {
    Orders newOrder;
    newOrder.orderId = ctr++;
    //Inserting Values
    std::cout << "Enter price: ";
    std::cin >> newOrder.bidPrice;
    std::cout << "Enter quantity: ";
    std::cin >> newOrder.quantity;
    if(newOrder.quantity == 0) return;

    order.push_back(newOrder);
    std::cout << "Order added!\n";
    buffer();
}

void showTrades(const std::vector<Orders>& order){//Shows trade
        for (int i = 0; i < order.size(); i++) {
        std::cout << "Order ID: " << order[i].orderId
                  << ", Price: " << order[i].bidPrice
                  << ", Quantity: " << order[i].quantity << "\n";
    }
    buffer();
}

int main() {//main function
    Stocks s;
    std::vector<Orders> order;
    while(true){
    int ch;

    std::cout << "=== Open Market ===\n";
    std::cout << "Seller A: " << s.askPrice1 << "\nSeller B: " << s.askPrice2 << "\nSeller C: " << s.askPrice3;
    std::cout << "\n\n[1] Add bid/s\n[2]Close Trade\n[3]Show Trades\n[0]Exit\nEnter choice: ";
    std::cin >> ch;

    switch (ch) {
        case 1: addOrder(order); break;
        case 2: closeTrade(order); break;
        case 3: showTrades(order); break;
        case 0: return 0; break;
    }
}
       return 0;
}
