@.strdouble = private unnamed_addr constant [5 x i8] c"%lf\0A\00", align 1
@.strint = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@.str = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
define i32 @printdouble(double %value) {
entry:
  call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @.strdouble, i64 0, i64 0), double %value)
  ret i32 0
}
define i32 @printint(i32 %value) {
entry:
  call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.strint, i64 0, i64 0), i32 %value)
  ret i32 0
}
declare i32 @printf(i8* nocapture readonly, ...) local_unnamed_addr #1
declare i32 @puts(i8*)

define i32 @Int(double %value) {
entry:
%0 = fptosi double %value to i32
ret i32 %0
}

define double @Double(i32 %value) {
entry:
%0 = sitofp i32 %value to double
ret double %0
}
define i32 @main() local_unnamed_addr {

%1 = alloca [8 x i32], align 4
%2 = getelementptr inbounds [8 x i32], [8 x i32]* %1, i64 0, i32 0
store i32 8, i32* %2, align 4
%3 = getelementptr inbounds [8 x i32], [8 x i32]* %1, i64 0, i32 1
store i32 -11, i32* %3, align 4
%4 = getelementptr inbounds [8 x i32], [8 x i32]* %1, i64 0, i32 2
store i32 -11, i32* %4, align 4
%5 = getelementptr inbounds [8 x i32], [8 x i32]* %1, i64 0, i32 3
store i32 6, i32* %5, align 4
%6 = getelementptr inbounds [8 x i32], [8 x i32]* %1, i64 0, i32 4
store i32 18, i32* %6, align 4
%7 = getelementptr inbounds [8 x i32], [8 x i32]* %1, i64 0, i32 5
store i32 14, i32* %7, align 4
%8 = getelementptr inbounds [8 x i32], [8 x i32]* %1, i64 0, i32 6
store i32 0, i32* %8, align 4
%9 = getelementptr inbounds [8 x i32], [8 x i32]* %1, i64 0, i32 7
store i32 1, i32* %9, align 4
%10 = alloca i32, align 4
store i32 0, i32* %10, align 4
%11 = load i32,i32* %10, align 4
%12 = alloca i32, align 4
store i32 8, i32* %12, align 4
%13 = load i32,i32* %12, align 4
%14 = alloca i32, align 4
store i32 1, i32* %14, align 4
%15 = load i32,i32* %14, align 4
%16 = alloca i32, align 4
store i32 1, i32* %16, align 4
%17 = load i32,i32* %16, align 4
%18 = alloca i32, align 4
store i32 0, i32* %18, align 4
%19 = load i32,i32* %18, align 4
br label %20

; <label>:20:
%21 = alloca i32, align 4
store i32 1, i32* %21, align 4
%22 = load i32,i32* %21, align 4
br label %23

; <label>:23:
%24 = alloca i32, align 4
%25 = load i32,i32* %21, align 4
%26 = sub i32 %25, 1
%27 = alloca i32, align 4
store i32 %26, i32* %27, align 4
%28 = load i32,i32* %27, align 4
%29 = load i32,i32* %27, align 4
%30 = getelementptr inbounds [8 x i32], [8 x i32]* %1, i64 0, i32 %29
%31 = load i32, i32* %30, align 4
%32 = alloca i32, align 4
store i32 %31, i32* %32, align 4
%33 = load i32,i32* %32, align 4
store i32 %33, i32* %24, align 4
%34 = load i32,i32* %24, align 4
%35 = alloca i32, align 4
%36 = load i32,i32* %21, align 4
%37 = getelementptr inbounds [8 x i32], [8 x i32]* %1, i64 0, i32 %36
%38 = load i32, i32* %37, align 4
%39 = alloca i32, align 4
store i32 %38, i32* %39, align 4
%40 = load i32,i32* %39, align 4
store i32 %40, i32* %35, align 4
%41 = load i32,i32* %35, align 4
%42 = load i32,i32* %14, align 4
%43 = load i32,i32* %16, align 4
%44 = icmp eq i32 %42, %43
br i1 %44, label %45, label %61

; <label>:45:
%46 = load i32,i32* %24, align 4
%47 = load i32,i32* %35, align 4
%48 = icmp slt i32 %46, %47
br i1 %48, label %49, label %60

; <label>:49:
%50 = load i32,i32* %21, align 4
%51 = sub i32 %50, 1
%52 = alloca i32, align 4
store i32 %51, i32* %52, align 4
%53 = load i32,i32* %52, align 4
%54 = load i32,i32* %52, align 4
%55 = load i32,i32* %35, align 4
%56 = getelementptr inbounds [8 x i32], [8 x i32]* %1, i64 0, i32 %54
store i32 %55, i32* %56, align 4
%57 = load i32,i32* %21, align 4
%58 = load i32,i32* %24, align 4
%59 = getelementptr inbounds [8 x i32], [8 x i32]* %1, i64 0, i32 %57
store i32 %58, i32* %59, align 4
br label %60

; <label>:60:
br label %61

; <label>:61:
%62 = load i32,i32* %14, align 4
%63 = load i32,i32* %18, align 4
%64 = icmp eq i32 %62, %63
br i1 %64, label %65, label %81

; <label>:65:
%66 = load i32,i32* %24, align 4
%67 = load i32,i32* %35, align 4
%68 = icmp sgt i32 %66, %67
br i1 %68, label %69, label %80

; <label>:69:
%70 = load i32,i32* %21, align 4
%71 = sub i32 %70, 1
%72 = alloca i32, align 4
store i32 %71, i32* %72, align 4
%73 = load i32,i32* %72, align 4
%74 = load i32,i32* %72, align 4
%75 = load i32,i32* %35, align 4
%76 = getelementptr inbounds [8 x i32], [8 x i32]* %1, i64 0, i32 %74
store i32 %75, i32* %76, align 4
%77 = load i32,i32* %21, align 4
%78 = load i32,i32* %24, align 4
%79 = getelementptr inbounds [8 x i32], [8 x i32]* %1, i64 0, i32 %77
store i32 %78, i32* %79, align 4
br label %80

; <label>:80:
br label %81

; <label>:81:
%82 = load i32,i32* %21, align 4
%83 = add i32 %82, 1
%84 = alloca i32, align 4
store i32 %83, i32* %84, align 4
%85 = load i32,i32* %84, align 4
%86 = load i32,i32* %84, align 4
store i32 %86, i32* %21, align 4
%87 = load i32,i32* %21, align 4
%88 = load i32,i32* %21, align 4
%89 = load i32,i32* %12, align 4
%90 = icmp slt i32 %88, %89
br i1 %90, label %23, label %91

; <label>:91:
%92 = load i32,i32* %10, align 4
%93 = add i32 %92, 1
%94 = alloca i32, align 4
store i32 %93, i32* %94, align 4
%95 = load i32,i32* %94, align 4
%96 = load i32,i32* %94, align 4
store i32 %96, i32* %10, align 4
%97 = load i32,i32* %10, align 4
%98 = load i32,i32* %10, align 4
%99 = load i32,i32* %12, align 4
%100 = icmp slt i32 %98, %99
br i1 %100, label %20, label %101

; <label>:101:
store i32 0, i32* %10, align 4
%102 = load i32,i32* %10, align 4
br label %103

; <label>:103:
%104 = alloca i32, align 4
%105 = load i32,i32* %10, align 4
%106 = getelementptr inbounds [8 x i32], [8 x i32]* %1, i64 0, i32 %105
%107 = load i32, i32* %106, align 4
%108 = alloca i32, align 4
store i32 %107, i32* %108, align 4
%109 = load i32,i32* %108, align 4
store i32 %109, i32* %104, align 4
%110 = load i32,i32* %104, align 4
%111 = load i32,i32* %104, align 4
call i32 @printint(i32 %111)
%113 = load i32,i32* %10, align 4
%114 = add i32 %113, 1
%115 = alloca i32, align 4
store i32 %114, i32* %115, align 4
%116 = load i32,i32* %115, align 4
%117 = load i32,i32* %115, align 4
store i32 %117, i32* %10, align 4
%118 = load i32,i32* %10, align 4
%119 = load i32,i32* %10, align 4
%120 = load i32,i32* %12, align 4
%121 = icmp slt i32 %119, %120
br i1 %121, label %103, label %122

; <label>:122: 
 ret i32 0 
 }