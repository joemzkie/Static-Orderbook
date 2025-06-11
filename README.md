# Static-Orderbook
My first time to create order book, using only static values for limit on quantity for trades. I hope to improve it.

L1 BBO Best bid offer/BBA Best bid ask
 - consider who wants to buy at the 
highest price vise versa. Price
Entity		Price		Quantity 	time
Buyer A		100		3		12:00
Buyer B		90		5		12:01
Buyer C		110		1		11:59

Seller A	110		3		-
Seller B	120		5		-
Seller C	120		1		-

The priority will be set as Buyer C Buys to Seller A
then lowest BBA to Highest BBO.

L2 MBP Market by price
- Same as L1 but it considers quantity, Highes quantity
gets the order first. Price > Quantity

L3 MBO Market by order
- Same as L2 but it considers time, First come First served.
Price > Qunatity > Time

Main
-> 1. add orders as many as you like.
-> 2. close the trades added, if no order added nothing happen
and exit the program.
-> 3. show all trades inserted.

the proccess to take priority of orders:
	
using the bool sorts through prio function,
 i sorted it by price > quantity > id which roughly 
follows the levels of orderbook above.
	
after being sorted the values in Stocks are put into
two separate arrays, ask price and seller quantity(asks, askQty).

the vector is alrade sorted, now it will make trades
that matched the condition:
	if bidPrice >= asks && askQty > 0
	
then it will exceute the code by decreasing the
quantity of how much was needed
	then it shows unmatched quantity, but stil a trade

then ignore all the trades that doesn't go through

Node: This Proect contains static values for limit on how much
quantity it have. This is my first time to this kind of proect
and i might improve it. 
