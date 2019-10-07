var test=[8.1,-11.1,-11.9,6.1,18.1]
var iterbegin=0
var iterend=5
while iterbegin<iterend{
	var iterbegin2=1;
	while iterbegin2<iterend{        
		var massivellast:Double = test[iterbegin2-1]
		var massivelcurrent:Double = test[iterbegin2]
		if massivellast<massivelcurrent{
			test[iterbegin2-1] = massivelcurrent
			test[iterbegin2] = massivellast
		}
		iterbegin2 = iterbegin2+1
	}
	iterbegin = iterbegin+1
}
iterbegin=0
while iterbegin<iterend{        
	var massivelcurrent:Double = test[iterbegin]
	print(massivelcurrent)
	iterbegin = iterbegin+1
}
                              