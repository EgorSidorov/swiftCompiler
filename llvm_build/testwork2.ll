%class.LinkedList = type { %class.A*, %class.A*, %class.A* }
%class.A = type { i32, i32, i32, %class.A*, %class.A* }
%struct._iobuf = type { i8* }
%struct.__crt_locale_pointers = type { %struct.__crt_locale_data*, %struct.__crt_multibyte_data* }
%struct.__crt_locale_data = type opaque
%struct.__crt_multibyte_data = type opaque

$"\01?initial@LinkedList@@QEAAXXZ" = comdat any

$"\01?setcurrentvalue@LinkedList@@QEAAXXZ" = comdat any

$"\01?push@LinkedList@@QEAAXXZ" = comdat any

$"\01?pop@LinkedList@@QEAAXXZ" = comdat any

$"\01?printall@LinkedList@@QEAAXXZ" = comdat any

$"\01?revert@LinkedList@@QEAAXXZ" = comdat any

$"\01??0A@@QEAA@XZ" = comdat any

$printf = comdat any

$_vfprintf_l = comdat any

$__local_stdio_printf_options = comdat any

$"\01??_C@_03PMGGPEJJ@?$CFd?6?$AA@" = comdat any

$"\01?_OptionsStorage@?1??__local_stdio_printf_options@@9@4_KA" = comdat any

@"\01??_C@_03PMGGPEJJ@?$CFd?6?$AA@" = linkonce_odr unnamed_addr constant [4 x i8] c"%d\0A\00", comdat, align 1
@"\01?_OptionsStorage@?1??__local_stdio_printf_options@@9@4_KA" = linkonce_odr global i64 0, comdat, align 8

; Function Attrs: nobuiltin
declare noalias i8* @"\01??2@YAPEAX_K@Z"(i64) #1

; Function Attrs: noinline optnone uwtable
define linkonce_odr void @"\01?initial@LinkedList@@QEAAXXZ"(%class.LinkedList*) #2 comdat align 2 personality i8* bitcast (i32 (...)* @__CxxFrameHandler3 to i8*) {
  %2 = alloca %class.LinkedList*, align 8
  store %class.LinkedList* %0, %class.LinkedList** %2, align 8
  %3 = load %class.LinkedList*, %class.LinkedList** %2, align 8
  %4 = call i8* @"\01??2@YAPEAX_K@Z"(i64 32) #7
  %5 = bitcast i8* %4 to %class.A*
  %6 = invoke %class.A* @"\01??0A@@QEAA@XZ"(%class.A* %5)
          to label %7 unwind label %18

; <label>:7:                                      ; preds = %1
  %8 = getelementptr inbounds %class.LinkedList, %class.LinkedList* %3, i32 0, i32 0
  store %class.A* %5, %class.A** %8, align 8
  %9 = getelementptr inbounds %class.LinkedList, %class.LinkedList* %3, i32 0, i32 0
  %10 = load %class.A*, %class.A** %9, align 8
  %11 = getelementptr inbounds %class.A, %class.A* %10, i32 0, i32 2
  store i32 0, i32* %11, align 8
  %12 = getelementptr inbounds %class.LinkedList, %class.LinkedList* %3, i32 0, i32 0
  %13 = load %class.A*, %class.A** %12, align 8
  %14 = getelementptr inbounds %class.LinkedList, %class.LinkedList* %3, i32 0, i32 1
  store %class.A* %13, %class.A** %14, align 8
  %15 = getelementptr inbounds %class.LinkedList, %class.LinkedList* %3, i32 0, i32 0
  %16 = load %class.A*, %class.A** %15, align 8
  %17 = getelementptr inbounds %class.LinkedList, %class.LinkedList* %3, i32 0, i32 2
  store %class.A* %16, %class.A** %17, align 8
  ret void

; <label>:18:                                     ; preds = %1
  %19 = cleanuppad within none []
  call void @"\01??3@YAXPEAX@Z"(i8* %4) #8 [ "funclet"(token %19) ]
  cleanupret from %19 unwind to caller
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr void @"\01?setcurrentvalue@LinkedList@@QEAAXXZ"(%class.LinkedList*, i32) #3 comdat align 2 {
  %3 = alloca i32, align 4
  %4 = alloca %class.LinkedList*, align 8
  store i32 %1, i32* %3, align 4
  store %class.LinkedList* %0, %class.LinkedList** %4, align 8
  %5 = load %class.LinkedList*, %class.LinkedList** %4, align 8
  %6 = load i32, i32* %3, align 4
  %7 = getelementptr inbounds %class.LinkedList, %class.LinkedList* %5, i32 0, i32 0
  %8 = load %class.A*, %class.A** %7, align 8
  %9 = getelementptr inbounds %class.A, %class.A* %8, i32 0, i32 2
  store i32 %6, i32* %9, align 8
  ret void
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr void @"\01?push@LinkedList@@QEAAXXZ"(%class.LinkedList*, i32) #2 comdat align 2 personality i8* bitcast (i32 (...)* @__CxxFrameHandler3 to i8*) {
  %3 = alloca i32, align 4
  %4 = alloca %class.LinkedList*, align 8
  %5 = alloca %class.A*, align 8
  store i32 %1, i32* %3, align 4
  store %class.LinkedList* %0, %class.LinkedList** %4, align 8
  %6 = load %class.LinkedList*, %class.LinkedList** %4, align 8
  %7 = call i8* @"\01??2@YAPEAX_K@Z"(i64 32) #7
  %8 = bitcast i8* %7 to %class.A*
  %9 = invoke %class.A* @"\01??0A@@QEAA@XZ"(%class.A* %8)
          to label %10 unwind label %29

; <label>:10:                                     ; preds = %2
  store %class.A* %8, %class.A** %5, align 8
  %11 = load i32, i32* %3, align 4
  %12 = load %class.A*, %class.A** %5, align 8
  %13 = getelementptr inbounds %class.A, %class.A* %12, i32 0, i32 2
  store i32 %11, i32* %13, align 8
  %14 = getelementptr inbounds %class.LinkedList, %class.LinkedList* %6, i32 0, i32 2
  %15 = load %class.A*, %class.A** %14, align 8
  %16 = load %class.A*, %class.A** %5, align 8
  %17 = getelementptr inbounds %class.A, %class.A* %16, i32 0, i32 4
  store %class.A* %15, %class.A** %17, align 8
  %18 = load %class.A*, %class.A** %5, align 8
  %19 = getelementptr inbounds %class.A, %class.A* %18, i32 0, i32 0
  store i32 1, i32* %19, align 8
  %20 = load %class.A*, %class.A** %5, align 8
  %21 = getelementptr inbounds %class.LinkedList, %class.LinkedList* %6, i32 0, i32 2
  %22 = load %class.A*, %class.A** %21, align 8
  %23 = getelementptr inbounds %class.A, %class.A* %22, i32 0, i32 3
  store %class.A* %20, %class.A** %23, align 8
  %24 = getelementptr inbounds %class.LinkedList, %class.LinkedList* %6, i32 0, i32 2
  %25 = load %class.A*, %class.A** %24, align 8
  %26 = getelementptr inbounds %class.A, %class.A* %25, i32 0, i32 1
  store i32 1, i32* %26, align 4
  %27 = load %class.A*, %class.A** %5, align 8
  %28 = getelementptr inbounds %class.LinkedList, %class.LinkedList* %6, i32 0, i32 2
  store %class.A* %27, %class.A** %28, align 8
  ret void

; <label>:29:                                     ; preds = %2
  %30 = cleanuppad within none []
  call void @"\01??3@YAXPEAX@Z"(i8* %7) #8 [ "funclet"(token %30) ]
  cleanupret from %30 unwind to caller
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr void @"\01?pop@LinkedList@@QEAAXXZ"(%class.LinkedList*) #3 comdat align 2 {
  %2 = alloca %class.LinkedList*, align 8
  store %class.LinkedList* %0, %class.LinkedList** %2, align 8
  %3 = load %class.LinkedList*, %class.LinkedList** %2, align 8
  %4 = getelementptr inbounds %class.LinkedList, %class.LinkedList* %3, i32 0, i32 2
  %5 = load %class.A*, %class.A** %4, align 8
  %6 = getelementptr inbounds %class.A, %class.A* %5, i32 0, i32 4
  %7 = load %class.A*, %class.A** %6, align 8
  %8 = getelementptr inbounds %class.LinkedList, %class.LinkedList* %3, i32 0, i32 2
  store %class.A* %7, %class.A** %8, align 8
  %9 = getelementptr inbounds %class.LinkedList, %class.LinkedList* %3, i32 0, i32 2
  %10 = load %class.A*, %class.A** %9, align 8
  %11 = getelementptr inbounds %class.A, %class.A* %10, i32 0, i32 1
  store i32 0, i32* %11, align 4
  ret void
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr void @"\01?printall@LinkedList@@QEAAXXZ"(%class.LinkedList*) #2 comdat align 2 {
  %2 = alloca %class.LinkedList*, align 8
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  store %class.LinkedList* %0, %class.LinkedList** %2, align 8
  %7 = load %class.LinkedList*, %class.LinkedList** %2, align 8
  %8 = getelementptr inbounds %class.LinkedList, %class.LinkedList* %7, i32 0, i32 1
  %9 = load %class.A*, %class.A** %8, align 8
  %10 = getelementptr inbounds %class.LinkedList, %class.LinkedList* %7, i32 0, i32 0
  store %class.A* %9, %class.A** %10, align 8
  %11 = getelementptr inbounds %class.LinkedList, %class.LinkedList* %7, i32 0, i32 0
  %12 = load %class.A*, %class.A** %11, align 8
  %13 = getelementptr inbounds %class.A, %class.A* %12, i32 0, i32 1
  %14 = load i32, i32* %13, align 4
  store i32 %14, i32* %3, align 4
  store i32 1, i32* %4, align 4
  br label %15

; <label>:15:                                     ; preds = %44, %1
  %16 = load i32, i32* %3, align 4
  %17 = load i32, i32* %4, align 4
  %18 = icmp eq i32 %16, %17
  br i1 %18, label %19, label %45

; <label>:19:                                     ; preds = %15
  %20 = getelementptr inbounds %class.LinkedList, %class.LinkedList* %7, i32 0, i32 0
  %21 = load %class.A*, %class.A** %20, align 8
  %22 = getelementptr inbounds %class.A, %class.A* %21, i32 0, i32 2
  %23 = load i32, i32* %22, align 8
  store i32 %23, i32* %5, align 4
  %24 = load i32, i32* %5, align 4
  %25 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @"\01??_C@_03PMGGPEJJ@?$CFd?6?$AA@", i32 0, i32 0), i32 %24)
  %26 = getelementptr inbounds %class.LinkedList, %class.LinkedList* %7, i32 0, i32 0
  %27 = load %class.A*, %class.A** %26, align 8
  %28 = getelementptr inbounds %class.A, %class.A* %27, i32 0, i32 1
  %29 = load i32, i32* %28, align 4
  store i32 %29, i32* %6, align 4
  %30 = load i32, i32* %6, align 4
  %31 = load i32, i32* %4, align 4
  %32 = icmp eq i32 %30, %31
  br i1 %32, label %33, label %39

; <label>:33:                                     ; preds = %19
  %34 = getelementptr inbounds %class.LinkedList, %class.LinkedList* %7, i32 0, i32 0
  %35 = load %class.A*, %class.A** %34, align 8
  %36 = getelementptr inbounds %class.A, %class.A* %35, i32 0, i32 3
  %37 = load %class.A*, %class.A** %36, align 8
  %38 = getelementptr inbounds %class.LinkedList, %class.LinkedList* %7, i32 0, i32 0
  store %class.A* %37, %class.A** %38, align 8
  br label %39

; <label>:39:                                     ; preds = %33, %19
  %40 = load i32, i32* %6, align 4
  %41 = load i32, i32* %4, align 4
  %42 = icmp slt i32 %40, %41
  br i1 %42, label %43, label %44

; <label>:43:                                     ; preds = %39
  store i32 0, i32* %3, align 4
  br label %44

; <label>:44:                                     ; preds = %43, %39
  br label %15

; <label>:45:                                     ; preds = %15
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr void @"\01?revert@LinkedList@@QEAAXXZ"(%class.LinkedList*) #3 comdat align 2 {
  %2 = alloca %class.LinkedList*, align 8
  %3 = alloca %class.A*, align 8
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  %7 = alloca %class.A*, align 8
  %8 = alloca i32, align 4
  %9 = alloca i32, align 4
  %10 = alloca %class.A*, align 8
  %11 = alloca %class.A*, align 8
  store %class.LinkedList* %0, %class.LinkedList** %2, align 8
  %12 = load %class.LinkedList*, %class.LinkedList** %2, align 8
  %13 = getelementptr inbounds %class.LinkedList, %class.LinkedList* %12, i32 0, i32 1
  %14 = load %class.A*, %class.A** %13, align 8
  store %class.A* %14, %class.A** %3, align 8
  %15 = getelementptr inbounds %class.LinkedList, %class.LinkedList* %12, i32 0, i32 2
  %16 = load %class.A*, %class.A** %15, align 8
  %17 = getelementptr inbounds %class.LinkedList, %class.LinkedList* %12, i32 0, i32 1
  store %class.A* %16, %class.A** %17, align 8
  store i32 1, i32* %4, align 4
  store i32 1, i32* %5, align 4
  %18 = getelementptr inbounds %class.LinkedList, %class.LinkedList* %12, i32 0, i32 1
  %19 = load %class.A*, %class.A** %18, align 8
  %20 = getelementptr inbounds %class.LinkedList, %class.LinkedList* %12, i32 0, i32 0
  store %class.A* %19, %class.A** %20, align 8
  br label %21

; <label>:21:                                     ; preds = %90, %1
  %22 = load i32, i32* %4, align 4
  %23 = load i32, i32* %5, align 4
  %24 = icmp eq i32 %22, %23
  br i1 %24, label %25, label %91

; <label>:25:                                     ; preds = %21
  %26 = getelementptr inbounds %class.LinkedList, %class.LinkedList* %12, i32 0, i32 0
  %27 = load %class.A*, %class.A** %26, align 8
  %28 = getelementptr inbounds %class.A, %class.A* %27, i32 0, i32 2
  %29 = load i32, i32* %28, align 8
  store i32 %29, i32* %6, align 4
  %30 = getelementptr inbounds %class.LinkedList, %class.LinkedList* %12, i32 0, i32 0
  %31 = load %class.A*, %class.A** %30, align 8
  store %class.A* %31, %class.A** %7, align 8
  %32 = getelementptr inbounds %class.LinkedList, %class.LinkedList* %12, i32 0, i32 0
  %33 = load %class.A*, %class.A** %32, align 8
  %34 = getelementptr inbounds %class.A, %class.A* %33, i32 0, i32 0
  %35 = load i32, i32* %34, align 8
  store i32 %35, i32* %8, align 4
  %36 = getelementptr inbounds %class.LinkedList, %class.LinkedList* %12, i32 0, i32 0
  %37 = load %class.A*, %class.A** %36, align 8
  %38 = getelementptr inbounds %class.A, %class.A* %37, i32 0, i32 1
  %39 = load i32, i32* %38, align 4
  store i32 %39, i32* %9, align 4
  %40 = getelementptr inbounds %class.LinkedList, %class.LinkedList* %12, i32 0, i32 0
  %41 = load %class.A*, %class.A** %40, align 8
  %42 = getelementptr inbounds %class.A, %class.A* %41, i32 0, i32 4
  %43 = load %class.A*, %class.A** %42, align 8
  store %class.A* %43, %class.A** %10, align 8
  %44 = getelementptr inbounds %class.LinkedList, %class.LinkedList* %12, i32 0, i32 0
  %45 = load %class.A*, %class.A** %44, align 8
  %46 = getelementptr inbounds %class.A, %class.A* %45, i32 0, i32 3
  %47 = load %class.A*, %class.A** %46, align 8
  store %class.A* %47, %class.A** %11, align 8
  %48 = load i32, i32* %8, align 4
  %49 = load i32, i32* %5, align 4
  %50 = icmp eq i32 %48, %49
  br i1 %50, label %51, label %71

; <label>:51:                                     ; preds = %25
  %52 = load i32, i32* %8, align 4
  %53 = getelementptr inbounds %class.LinkedList, %class.LinkedList* %12, i32 0, i32 0
  %54 = load %class.A*, %class.A** %53, align 8
  %55 = getelementptr inbounds %class.A, %class.A* %54, i32 0, i32 1
  store i32 %52, i32* %55, align 4
  %56 = load i32, i32* %9, align 4
  %57 = getelementptr inbounds %class.LinkedList, %class.LinkedList* %12, i32 0, i32 0
  %58 = load %class.A*, %class.A** %57, align 8
  %59 = getelementptr inbounds %class.A, %class.A* %58, i32 0, i32 0
  store i32 %56, i32* %59, align 8
  %60 = getelementptr inbounds %class.LinkedList, %class.LinkedList* %12, i32 0, i32 0
  %61 = load %class.A*, %class.A** %60, align 8
  %62 = getelementptr inbounds %class.A, %class.A* %61, i32 0, i32 4
  %63 = load %class.A*, %class.A** %62, align 8
  %64 = getelementptr inbounds %class.LinkedList, %class.LinkedList* %12, i32 0, i32 0
  store %class.A* %63, %class.A** %64, align 8
  %65 = load %class.A*, %class.A** %10, align 8
  %66 = load %class.A*, %class.A** %7, align 8
  %67 = getelementptr inbounds %class.A, %class.A* %66, i32 0, i32 3
  store %class.A* %65, %class.A** %67, align 8
  %68 = load %class.A*, %class.A** %11, align 8
  %69 = load %class.A*, %class.A** %7, align 8
  %70 = getelementptr inbounds %class.A, %class.A* %69, i32 0, i32 4
  store %class.A* %68, %class.A** %70, align 8
  br label %71

; <label>:71:                                     ; preds = %51, %25
  %72 = load i32, i32* %8, align 4
  %73 = load i32, i32* %5, align 4
  %74 = icmp slt i32 %72, %73
  br i1 %74, label %75, label %90

; <label>:75:                                     ; preds = %71
  %76 = load i32, i32* %8, align 4
  %77 = getelementptr inbounds %class.LinkedList, %class.LinkedList* %12, i32 0, i32 0
  %78 = load %class.A*, %class.A** %77, align 8
  %79 = getelementptr inbounds %class.A, %class.A* %78, i32 0, i32 1
  store i32 %76, i32* %79, align 4
  %80 = load i32, i32* %9, align 4
  %81 = getelementptr inbounds %class.LinkedList, %class.LinkedList* %12, i32 0, i32 0
  %82 = load %class.A*, %class.A** %81, align 8
  %83 = getelementptr inbounds %class.A, %class.A* %82, i32 0, i32 0
  store i32 %80, i32* %83, align 8
  %84 = load %class.A*, %class.A** %10, align 8
  %85 = load %class.A*, %class.A** %7, align 8
  %86 = getelementptr inbounds %class.A, %class.A* %85, i32 0, i32 3
  store %class.A* %84, %class.A** %86, align 8
  %87 = load %class.A*, %class.A** %11, align 8
  %88 = load %class.A*, %class.A** %7, align 8
  %89 = getelementptr inbounds %class.A, %class.A* %88, i32 0, i32 4
  store %class.A* %87, %class.A** %89, align 8
  store i32 0, i32* %4, align 4
  br label %90

; <label>:90:                                     ; preds = %75, %71
  br label %21

; <label>:91:                                     ; preds = %21
  %92 = load %class.A*, %class.A** %3, align 8
  %93 = getelementptr inbounds %class.LinkedList, %class.LinkedList* %12, i32 0, i32 2
  store %class.A* %92, %class.A** %93, align 8
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr %class.A* @"\01??0A@@QEAA@XZ"(%class.A* returned) unnamed_addr #3 comdat align 2 {
  %2 = alloca %class.A*, align 8
  store %class.A* %0, %class.A** %2, align 8
  %3 = load %class.A*, %class.A** %2, align 8
  %4 = getelementptr inbounds %class.A, %class.A* %3, i32 0, i32 0
  store i32 0, i32* %4, align 8
  %5 = getelementptr inbounds %class.A, %class.A* %3, i32 0, i32 1
  store i32 0, i32* %5, align 4
  %6 = getelementptr inbounds %class.A, %class.A* %3, i32 0, i32 2
  store i32 0, i32* %6, align 8
  ret %class.A* %3
}

declare i32 @__CxxFrameHandler3(...)

; Function Attrs: nobuiltin nounwind
declare void @"\01??3@YAXPEAX@Z"(i8*) #4

; Function Attrs: nounwind
declare void @llvm.va_start(i8*) #5

; Function Attrs: noinline optnone uwtable
define linkonce_odr i32 @_vfprintf_l(%struct._iobuf*, i8*, %struct.__crt_locale_pointers*, i8*) #2 comdat {
  %5 = alloca i8*, align 8
  %6 = alloca %struct.__crt_locale_pointers*, align 8
  %7 = alloca i8*, align 8
  %8 = alloca %struct._iobuf*, align 8
  store i8* %3, i8** %5, align 8
  store %struct.__crt_locale_pointers* %2, %struct.__crt_locale_pointers** %6, align 8
  store i8* %1, i8** %7, align 8
  store %struct._iobuf* %0, %struct._iobuf** %8, align 8
  %9 = load i8*, i8** %5, align 8
  %10 = load %struct.__crt_locale_pointers*, %struct.__crt_locale_pointers** %6, align 8
  %11 = load i8*, i8** %7, align 8
  %12 = load %struct._iobuf*, %struct._iobuf** %8, align 8
  %13 = call i64* @__local_stdio_printf_options()
  %14 = load i64, i64* %13, align 8
  %15 = call i32 @__stdio_common_vfprintf(i64 %14, %struct._iobuf* %12, i8* %11, %struct.__crt_locale_pointers* %10, i8* %9)
  ret i32 %15
}

declare %struct._iobuf* @__acrt_iob_func(i32) #6

; Function Attrs: nounwind
declare void @llvm.va_end(i8*) #5

declare i32 @__stdio_common_vfprintf(i64, %struct._iobuf*, i8*, %struct.__crt_locale_pointers*, i8*) #6

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr i64* @__local_stdio_printf_options() #3 comdat {
  ret i64* @"\01?_OptionsStorage@?1??__local_stdio_printf_options@@9@4_KA"
}