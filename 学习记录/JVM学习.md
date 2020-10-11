# JVM（Java Virtual Machine）
## JVM 简介
所有加java程序的运行都要依靠具体的java虚拟机实例，java虚拟机是一个抽象的体系结构，具有平台无关性和语言无关性。
* 平台无关性：任何平台只要装载JVM，.class文件（字节码文件）就可以在其上运行。
* 语言无关性：不同语言只要能编译成 .class文件，就可以在JVM上运行。

## 从JRE、JDK和JVM的关系来看JAVA程序执行过程
* JDK（Java Development Kit，Java开发工具包）是用来编译、调试Java程序的开发工具包。包括 JRE 及编译器和调试器等用于程序开发的文件。具体来说有Java工具（javac/java/jdb等）和Java基础的类库（java API ）
* JRE（Java Runtime Environment， Java运行环境）是Java平台，所有的程序都要在JRE下才能够运行。包括JVM和Java核心类库和支持文件。
* JVM(Java Virtual Machine)：Java 虚拟机，它也定义了指令集、寄存器集、结构栈、垃圾收集堆、内存区域，负责解释运行*.class 字节码文件，边解释边运行。Java 虚拟机机制是实现可移植性的核心机制。不同的操作系统有不同的虚拟机，Java虚拟机机制屏蔽了底层运行平台的差别，使 Java 语言在不同平台上运行时不需要重新编译，实现了一次编写，到处运行。

下图表示了JDK、JRE和JVM三者间的关系：

![](B:\MyGithub\Linux-Learning\pictures\jdkjvmjre关系.png)
