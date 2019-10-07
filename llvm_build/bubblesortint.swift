var test=[8,-11,-11,6,18,14,0,1]
var iterbegin = 0
var iterend = 8
var desc = 1
var truee = 1
var falsee = 0
while iterbegin<iterend{
	var iterbegin2=1;
	while iterbegin2<iterend{        
		var massivellast:Int = test[iterbegin2-1]
		var massivelcurrent:Int = test[iterbegin2]
		if desc==truee{
			if massivellast<massivelcurrent{
				test[iterbegin2-1] = massivelcurrent
				test[iterbegin2] = massivellast
			}
		}
		if desc==falsee{
			if massivellast>massivelcurrent{
				test[iterbegin2-1] = massivelcurrent
				test[iterbegin2] = massivellast
			}
		}
		iterbegin2 = iterbegin2+1
	}
	iterbegin = iterbegin+1
}
iterbegin=0
while iterbegin<iterend{        
	var massivelcurrent:Int = test[iterbegin]
	print(massivelcurrent)
	iterbegin = iterbegin+1
}
                              