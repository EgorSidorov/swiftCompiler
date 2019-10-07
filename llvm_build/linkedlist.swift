class A{
	var haslast = 0;
	var hasnext = 0;
	var value = 0;
	var next : A?;
	var last : A?;
};

class List{
    var current : A?;
    var begin : A?;
    var end : A?;
    func push(_ value :Int){
         let newval = A();
         newval.value = value;
         newval.last = end;
         newval.haslast = 1;
         end!.next = newval;
         end!.hasnext = 1;
         end = newval;
    };
    func setcurrentvalue(_ value :Int){
		current!.value = value;
    };
    func pop(){
		end = end!.last!;
        end!.hasnext = 0;
    };
    func initial(){
	    current = A();
        current!.value = 0;
        begin = current;
        end = current;
    };
    func printall(){
	    current = begin;
        var hasnext = current!.hasnext;
        var booltrue = 1;
        while hasnext==booltrue{
            var currval = current!.value;
            print(currval);
            var hasnextcurr = current!.hasnext;
            if hasnextcurr==booltrue{
                current = current!.next
            };
            if hasnextcurr<booltrue{
                hasnext = 0;
            };      
        };
    };
    func revert(){
	    var copybegin = begin;
        begin = end;
        var haslast = 1;
        var booltrue = 1;
        current = begin;
        while haslast==booltrue{
            var currval = current!.value;
            var curr = current!;
            var haslastcurr = current!.haslast;
            var hasnextcurr = current!.hasnext;
            var lastcurr = current!.last;
            var nextcurr = current!.next;
            if haslastcurr==booltrue{
                current!.hasnext = haslastcurr;
                current!.haslast = hasnextcurr;
                current = current!.last
                curr.next = lastcurr;
                curr.last = nextcurr;
            };
            if haslastcurr<booltrue{
                current!.hasnext = haslastcurr;
                current!.haslast = hasnextcurr;
                curr.next = lastcurr;
                curr.last = nextcurr;
                haslast = 0;
            }; 
        };
        end = copybegin;
    };
};

let list2 = List();
list2.initial();
list2.setcurrentvalue(2);
list2.push(5);
list2.pop();
list2.push(11);
list2.push(18);
list2.printall();
list2.revert();
list2.printall();
list2.revert();
list2.printall();