/*
Iteration(=Loops), Line Drawing - with data validation
선입력, 후 검사. 
do{
	//things you want to repeat in a loop
}while (<check to keep going with loop>);

[do-while loop] is rarely used in practice
    - it is harder to see the condition for how the loop will end.
    - whiles are superior to do-whiles (while loops are generally reperred)
    - One of the advantages of using a do while 
        : we do not have to repeat the prompt and read code 
          as we will do one read before we decide if we wish to continue. 
          If we do not want an error message, then a do-while loop is more succinct

*/
//이 구조는 유효하지 않은 입력이 들어왔을 때 사용자에게 경고하는 본래의 오류 검사 기능을 제대로 수행하지 못하는 비효율적인 코드
//first run is truthy when it is the first run of the loop
	int firstRun = 1;
	do{
		//when testing for something that is truthy or falsey, we should
		//always test against 0.  This is because 0 is the only false value
		//while every non-zero is true.  It is far safer to always test
		//against 0.
		if(firstRun != 0){
			//print error message
			printf("Error: Number of stars must be between 0 and 50 inclusive.");
			//update firstRun variable
			firstRun = 0;
		}
		//prompt and read
		printf("Please enter number of stars on the line: ");
		scanf("%d", &numStars);

	}while(numStars < 0 || numStars > 50);

//사용자가 유효하지 않은 값을 입력했을 때만' 오류 메시지를 출력하고 재입력을 요구하는, 일반적이고 효율적인 유효성 검사 사이클을 따른다
do{
		//prompt and read
		printf("Please enter number of stars on the line: ");
		scanf("%d", &numStars);

		//if it is not correct, we need to print error
		if(numStars < 0 || numStars > 50){
			//print error message
			printf("Number of stars must be between 0 and 50 inclusive.");
		}
	}while(numStars < 0 || numStars > 50);