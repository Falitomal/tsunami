<h1 align="center">
  tsunami - 42 Bootcamp Cybersec
</h1>

<p align="center">
	<b><i>OTP (Time-Based One Time Password)</i></b><br>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/Falitomal/tsunami?color=lightblue" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/Falitomal/tsunami?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/Falitomal/tsunami?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/Falitomal/tsunami?color=green" />
</p>



## ✏️ Summary
```

The Tsunami project consists of creating a buffer overflow vulnerable program and another program that exploits this vulnerability to execute the calculator.

For this project, a Vagrantfile is used to emulate a 32-bit Windows XP machine where the entire process will be performed.

The project follows the explanation provided on this page, but a brief explanation of the code will also be provided here.

```
## 💡 Example 

```

The procedure consists of two phases: creating the vulnerable program [code_vulnerability.c] and constructing the payload that will be sent to exploit it during execution. Once the vulnerable executable is created and verified, an exploit is developed to take advantage of the vulnerability.

During the execution of the vulnerable program, a call to the strcpy function in the DLL msvcrt.dll occurs. After this call, the return address is pushed onto the stack. To create the payload, a NULL byte (0x00) is placed on the stack to mark the end of the string for the command cmd.exe. This can cause issues with strcpy because if it encounters a NULL byte in a string, it stops copying the rest of the string. To work around this, the string "cmd.exe" is pushed onto the stack byte by byte.

To exploit the vulnerability, the address of the System() function in the DLL msvcrt.dll is needed. This address is obtained using the offset command, resulting in \x77\xc2\x93\xc7.

The exploit program [tsunami.c] is created, and it expects a single parameter as an argument. The payload is then constructed, containing the shellcode that will automatically open the Windows XP calculator when the vulnerability is exploited.

The shellcode includes the address of an instruction, JMP ESP, which will redirect program execution to the shellcode. The address for this instruction in the kernel32.dll is \x7C\x86\x46\x7B.

Please note that this description provides a high-level overview of the vulnerability and exploit process. For detailed information, refer to the relevant source files mentioned above.

