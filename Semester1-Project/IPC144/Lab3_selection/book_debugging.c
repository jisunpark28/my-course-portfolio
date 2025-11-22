// int ShippingCost(int Weight, int Distance){
// 	int my_result = 10.75;
// if(Weight > 5){
// my_result + 2.10(Weight) = my_result
// }
// 	else if(Distance > 600){
// 		my_rseult = 600 * 0.5
// 	}
// }


int ShippingCost(int Weight, int distance){
	double myResult = 10.75;
    int overDistance = distance -600;
    if(Weight > 5){
        myResult += 2.10*(Weight-5);
    }
	if(distance > 600){
		myResult += (overDistance/10)*0.05 + (overDistance%10)*0.05;
	}
    return myResult;
}

