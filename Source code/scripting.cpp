

#include "stdafx.h"

boolean runningScript = false;

void print(char text[DIM], double result1, double result2) {
	int i = 0, j = 0, varAndValues = 0, k = 0, var2Print = 0, g = 0, valP = 0, l = 0, chChar = 0, b = 0, nV = 0, nC = 0;
	char toPrint[DIM], listValues[DIM], listText[DIM], varType[DIM], printing[DIM], varValue[DIM], finalString[DIM] = "";
	char specifier, clica = 39;
	for (i = 0; text[i] != '\0' && ((text[i] == '\"'&&text[i + 1] == ',') == false || (text[i] == '\"'&&text[i + 1] == '\"') == true && text[i + 2] != ','); i++) {
		listText[i] = text[i];
		if (listText[i - 1] == '%'&&listText[i] == 'd') {
			text[i] = 'i'; listText[i] = 'i';
		}
	}
	listText[i] = '\0';
	l = i;
	if (text[i + 1] == ',') {
		varAndValues = 1;
	}
	int v = 0;
	if (varAndValues == 0) {
		while (v < abs((int)strlen(listText))) {
			v++;
		}
		while (v < abs((int)strlen(text))) {
			listText[v] = text[v];
			v++;
		}
		listText[v] = '\0';
	}
	for (i = 0; listText[i] != '\0'; i++) {
		if (listText[i] == '\\'&&listText[i + 1] == 'n') {
			chChar = 1;
		}
		if (listText[i] == '\\'&&listText[i + 1] == 't') {
			chChar = 1;
		}
		if (listText[i] == '%'&&listText[i + 1] == '%') {
			chChar = 1;
		}
		if (listText[i] == '\\'&&listText[i + 1] == '\"') {
			chChar = 1;
		}
	}
	while (chChar == 1) {
		for (i = 0; listText[i] != '\0'; i++) {
			if (listText[i] == '\\'&&listText[i + 1] == 'n') {
				listText[i] = '\n';
				i++;
				while (listText[i + 1] != '\0') {
					listText[i] = listText[i + 1];
					i++;
				}
				listText[i] = '\0';
			}
			if (listText[i] == '\\'&&listText[i + 1] == 't') {
				listText[i] = '\t';
				i++;
				while (listText[i + 1] != '\0') {
					listText[i] = listText[i + 1];
					i++;
				}
				listText[i] = '\0';
			}
			if (listText[i] == '%'&&listText[i + 1] == '%') {
				listText[i] = '%';
				i++;
				while (listText[i + 1] != '\0') {
					listText[i] = listText[i + 1];
					i++;
				}
				listText[i] = '\0';
			}
			if (listText[i] == '\\'&&listText[i + 1] == '\"') {
				listText[i] = '\"';
				i++;
				while (listText[i + 1] != '\0') {
					listText[i] = listText[i + 1];
					i++;
				}
				listText[i] = '\0';
			}
		}
		chChar = 0;
		for (i = 0; listText[i] != '\0'; i++) {
			if (listText[i] == '\\'&&listText[i + 1] == 'n') {
				chChar = 1;
			}
			if (listText[i] == '\\'&&listText[i + 1] == 't') {
				chChar = 1;
			}
			if (listText[i] == '%'&&listText[i + 1] == '%') {
				chChar = 1;
			}
			if (listText[i] == '\\'&&listText[i + 1] == '\"') {
				chChar = 1;
			}
		}
	}
	if (varAndValues == 1) {
		i = l + 2;
		for (j = 0; text[i] != '\0'; j++) {
			listValues[j] = text[i];
			i++;
		}
		listValues[j] = '\0';
		g = 0;
		for (j = 0; listValues[j] != '\0'; j++) {
			if (listValues[j] != ' ') {
				listValues[g] = listValues[j];
				g++;
			}
		}
		listValues[g] = '\0';
		listValues[j] = '\0';
		nV = 1;
		for (b = 0; listValues[b] != '\0'; b++) {
			if (listValues[b] == ',') {
				nV++;
			}
		}
		nC = 0;
		for (b = 0; listText[b] != '\0'; b++) {
			if (listText[b] == '%'&&verify4Printf(listText[b + 1])) {
				b++;
				while (verify4Printf(listText[b]) && verifySpecifier(listText[b]) == 0) {
					b++;
				}
				if (verifySpecifier(listText[b])) {
					nC++;
				}
			}
		}
		if (nC == nV) {
			for (i = 0; listText[i] != '\0'; i++) {
				for (j = i; listText[j] != '\0'; j++) {
					if (listText[j] == '%'&&verify4Printf(listText[j + 1]) == false) {
						var2Print = 2;
						break;
					}
					if (listText[j] == '%'&&verify4Printf(listText[j + 1])) {
						var2Print = 1;
						break;
					}
				}
				if (var2Print == 1) {
					j = 0;
					while (!(listText[i] == '%'&&verify4Printf(listText[i + 1])) && listText[i + 1] != '\0') {
						toPrint[j] = listText[i];
						i++;
						j++;
					}
					toPrint[j] = '\0';
					k = 0;
					while (verify4Printf(listText[i]) && verifySpecifier(varType[k - 1]) == 0 && listText[i] != '\0') {
						varType[k] = listText[i];
						k++; i++;
					}
					varType[k] = '\0';
					if (strlen(toPrint) != 0 && strlen(varType) != 0) {
						sprintf(printing, "%s%s", toPrint, varType);
					}
					else {
						if (strlen(toPrint) != 0) {
							sprintf(printing, "%s", toPrint);
						}
						else {
							if (strlen(varType) != 0) {
								sprintf(printing, "%s", varType);
							}
						}
					}
					varValue[0] = '\0';
					g = 0;
					while (listValues[valP] != ','&&listValues[valP] != '\0') {
						varValue[g] = listValues[valP];
						g++; valP++;
					}
					valP++;
					varValue[g] = '\0';
					renamer(varValue);
					sprintf(varValue, expressionF);
					specifier = varType[strlen(varType) - 1];
					if (specifier == 'i' || specifier == 'd') {
						int value = (int)calcNow(varValue, result1, result2);
						printf(printing, value);
						value = 0;
					}
					if (specifier == 'u') {
						unsigned int value = (unsigned int)calcNow(varValue, result1, result2);
						printf(printing, value);
						value = 0;
					}
					if (specifier == 'o') {
						unsigned int value = (unsigned int)calcNow(varValue, result1, result2);
						printf(printing, value);
						value = 0;
					}
					if (specifier == 'x' || specifier == 'X') {
						unsigned int value = (unsigned int)calcNow(varValue, result1, result2);
						printf(printing, value);
						value = 0;
					}
					if (specifier == 'f') {
						float value = (float)calcNow(varValue, result1, result2);
						printf(printing, value);
						value = 0;
					}
					if (specifier == 'e' || specifier == 'E') {
						double value = calcNow(varValue, result1, result2);
						printf(printing, value);
						value = 0;
					}
					if (specifier == 'G' || specifier == 'g') {
						double value = calcNow(varValue, result1, result2);
						printf(printing, value);
						value = 0;
					}
					if (specifier == 'a' || specifier == 'A') {
						double value = calcNow(varValue, result1, result2);
						printf(printing, value);
						value = 0;
					}
					if (specifier == 'c') {
						char value = '0';
						int p = 0, h = 0;
						int charString = 0;
						for (p = 0; p < abs((int)strlen(varValue)); p++) {
							if (varValue[p] == '(') {
								charString++;
							}
							if (varValue[p] == ')') {
								charString++;
							}
						}
						if (varValue[0] == clica && varValue[2] == clica && abs((int)strlen(varValue)) == 3) {
							value = varValue[1];
							printf(printing, value);
						}
						else {
							if (charString == 2) {
								p = 0;
								char string[300] = "";
								char index[10] = "";
								while (varValue[p] != '('&&varValue[p] != '\0') {
									string[p] = varValue[p];
									p++;
								}
								string[p] = '\0';
								p++;
								h = 0;
								while (varValue[p] != ')'&&varValue[p] != '\0') {
									index[h] = varValue[p];
									p++; h++;
								}
								index[h] = '\0';
								int Index = (int)calcNow(index, result1, result2);
								renamer(string);
								for (h = 0; expressionF[h] != '\0'; h++) {
									string[h] = expressionF[h];
								}
								string[h] = '\0';
								stringVariableToString(string);
								printf(printing, variableSTring[Index]);
								charString = 0;
							}
							else {
								int valu = (int)calcNow(varValue, result1, result2);
								value = valu;
								printf(printing, value);
								value = 0;
							}
						}
					}
					if (specifier == 's') {
						int h = 0;
						renamer(varValue);
						for (h = 0; expressionF[h] != '\0'; h++) {
							varValue[h] = expressionF[h];
						}
						varValue[h] = '\0';
						stringVariableToString(varValue);
						printf(printing, variableSTring);
					}
					if (specifier == 'p') {
						int value = (int)calcNow(varValue, result1, result2);
						printf(printing, value);
						value = 0;
					}
					if (specifier == 'n') {
						signed int value = (int)calcNow(varValue, result1, result2);
						_set_printf_count_output(1);
						printf(printing, &value);
						_set_printf_count_output(0);
						value = 0;
					}
					i--;
				}
				if (var2Print == 2) {
					j = 0;
					while (!(listText[i - 1] == '%'&&verify4Printf(listText[i]) == 0) && listText[i] != '\0') {
						toPrint[j] = listText[i];
						i++;
						j++;
					}
					toPrint[j] = '\0';
					printf("%s", toPrint);
					i--;
				}
				if (var2Print == 0) {
					while (i < abs((int)strlen(listText))) {
						printf("%c", listText[i]);
						i++;
					}
				}
				var2Print = 0;
			}
			puts(" ");
		}
		else {
			puts("\n==> Error: The number of specifiers and the number of provided variables is not equal. <==\n");
		}
	}
	else {
		if (listText[strlen(listText) - 1] == '\"') {
			listText[strlen(listText) - 1] = '\0';
		}
		puts(listText);
	}
}

void sprint(char text[DIM], double result1, double result2) {
	int i = 0, j = 0, varAndValues = 0, k = 0, var2Print = 0, g = 0, valP = 0, l = 0, chChar = 0, b = 0, nV = 0, nC = 0;
	char toPrint[DIM], listValues[DIM], listText[DIM], varType[DIM], printing[DIM], varValue[DIM], variable[DIM] = "", String[DIM] = "", finalString[DIM] = "";
	char specifier, clica = 39;
	i = 0;
	while (verifyLetter(text[i]) || verifyNumber(text[i])) {
		variable[i] = text[i];
		i++;
	}
	variable[i] = '\0';
	i = i + 2;
	while (text[i] != '\0') {
		text[i - strlen(variable) - 2] = text[i];
		i++;
	}
	text[i - strlen(variable) - 2] = '\0';
	for (i = 0; text[i] != '\0' && ((text[i] == '\"'&&text[i + 1] == ',') == false || (text[i] == '\"'&&text[i + 1] == '\"') == true && text[i + 2] != ','); i++) {
		listText[i] = text[i];
		if (listText[i - 1] == '%'&&listText[i] == 'd') {
			text[i] = 'i'; listText[i] = 'i';
		}
	}
	listText[i] = '\0';
	l = i;
	if (text[i + 1] == ',') {
		varAndValues = 1;
	}
	for (i = 0; listText[i] != '\0'; i++) {
		if (listText[i] == '\\'&&listText[i + 1] == 'n') {
			chChar = 1;
		}
		if (listText[i] == '\\'&&listText[i + 1] == 't') {
			chChar = 1;
		}
		if (listText[i] == '%'&&listText[i + 1] == '%') {
			chChar = 1;
		}
		if (listText[i] == '\\'&&listText[i + 1] == '\"') {
			chChar = 1;
		}
	}
	while (chChar == 1) {
		for (i = 0; listText[i] != '\0'; i++) {
			if (listText[i] == '\\'&&listText[i + 1] == 'n') {
				listText[i] = '\n';
				i++;
				while (listText[i + 1] != '\0') {
					listText[i] = listText[i + 1];
					i++;
				}
				listText[i] = '\0';
			}
			if (listText[i] == '\\'&&listText[i + 1] == 't') {
				listText[i] = '\t';
				i++;
				while (listText[i + 1] != '\0') {
					listText[i] = listText[i + 1];
					i++;
				}
				listText[i] = '\0';
			}
			if (listText[i] == '%'&&listText[i + 1] == '%') {
				listText[i] = '%';
				i++;
				while (listText[i + 1] != '\0') {
					listText[i] = listText[i + 1];
					i++;
				}
				listText[i] = '\0';
			}
			if (listText[i] == '\\'&&listText[i + 1] == '\"') {
				listText[i] = '\"';
				i++;
				while (listText[i + 1] != '\0') {
					listText[i] = listText[i + 1];
					i++;
				}
				listText[i] = '\0';
			}
		}
		chChar = 0;
		for (i = 0; listText[i] != '\0'; i++) {
			if (listText[i] == '\\'&&listText[i + 1] == 'n') {
				chChar = 1;
			}
			if (listText[i] == '\\'&&listText[i + 1] == 't') {
				chChar = 1;
			}
			if (listText[i] == '%'&&listText[i + 1] == '%') {
				chChar = 1;
			}
			if (listText[i] == '\\'&&listText[i + 1] == '\"') {
				chChar = 1;
			}
		}
	}
	if (varAndValues == 1) {
		i = l + 2;
		for (j = 0; text[i] != '\0'; j++) {
			listValues[j] = text[i];
			i++;
		}
		listValues[j] = '\0';
		g = 0;
		for (j = 0; listValues[j] != '\0'; j++) {
			if (listValues[j] != ' ') {
				listValues[g] = listValues[j];
				g++;
			}
		}
		listValues[g] = '\0';
		nV = 1;
		for (b = 0; listValues[b] != '\0'; b++) {
			if (listValues[b] == ',') {
				nV++;
			}
		}
		nC = 0;
		for (b = 0; listText[b] != '\0'; b++) {
			if (listText[b] == '%'&&verify4Printf(listText[b + 1])) {
				b++;
				while (verify4Printf(listText[b]) && verifySpecifier(listText[b]) == 0) {
					b++;
				}
				if (verifySpecifier(listText[b])) {
					nC++;
				}
			}
		}
		if (nC == nV) {
			for (i = 0; listText[i] != '\0'; i++) {
				for (j = i; listText[j] != '\0'; j++) {
					if (listText[j] == '%'&&verify4Printf(listText[j + 1]) == false) {
						var2Print = 2;
						break;
					}
					if (listText[j] == '%'&&verify4Printf(listText[j + 1])) {
						var2Print = 1;
						break;
					}
				}
				if (var2Print == 1) {
					j = 0;
					while (!(listText[i] == '%'&&verify4Printf(listText[i + 1])) && listText[i + 1] != '\0') {
						toPrint[j] = listText[i];
						i++;
						j++;
					}
					toPrint[j] = '\0';
					k = 0;
					while (verify4Printf(listText[i]) && verifySpecifier(varType[k - 1]) == 0 && listText[i] != '\0') {
						varType[k] = listText[i];
						k++; i++;
					}
					varType[k] = '\0';
					sprintf(printing, "%s%s", toPrint, varType);
					varValue[0] = '\0';
					g = 0;
					while (listValues[valP] != ','&&listValues[valP] != '\0') {
						varValue[g] = listValues[valP];
						g++; valP++;
					}
					valP++;
					varValue[g] = '\0';
					renamer(varValue);
					sprintf(varValue, expressionF);
					specifier = varType[strlen(varType) - 1];
					if (specifier == 'i' || specifier == 'd') {
						int value = (int)calcNow(varValue, result1, result2);
						sprintf(String, printing, value);
						sprintf(finalString, "%s%s", finalString, String);
						value = 0;
					}
					if (specifier == 'u') {
						unsigned int value = (unsigned int)calcNow(varValue, result1, result2);
						sprintf(String, printing, value);
						sprintf(finalString, "%s%s", finalString, String);
						value = 0;
					}
					if (specifier == 'o') {
						unsigned int value = (unsigned int)calcNow(varValue, result1, result2);
						sprintf(String, printing, value);
						sprintf(finalString, "%s%s", finalString, String);
						value = 0;
					}
					if (specifier == 'x' || specifier == 'X') {
						unsigned int value = (unsigned int)calcNow(varValue, result1, result2);
						sprintf(String, printing, value);
						sprintf(finalString, "%s%s", finalString, String);
						value = 0;
					}
					if (specifier == 'f') {
						float value = (float)calcNow(varValue, result1, result2);
						sprintf(String, printing, value);
						sprintf(finalString, "%s%s", finalString, String);
						value = 0;
					}
					if (specifier == 'e' || specifier == 'E') {
						double value = calcNow(varValue, result1, result2);
						sprintf(String, printing, value);
						sprintf(finalString, "%s%s", finalString, String);
						value = 0;
					}
					if (specifier == 'G' || specifier == 'g') {
						double value = calcNow(varValue, result1, result2);
						sprintf(String, printing, value);
						sprintf(finalString, "%s%s", finalString, String);
						value = 0;
					}
					if (specifier == 'a' || specifier == 'A') {
						double value = calcNow(varValue, result1, result2);
						sprintf(String, printing, value);
						sprintf(finalString, "%s%s", finalString, String);
						value = 0;
					}
					if (specifier == 'c') {
						char value = '0';
						int p = 0, h = 0;
						int charString = 0;
						for (p = 0; p < abs((int)strlen(varValue)); p++) {
							if (varValue[p] == '(') {
								charString++;
							}
							if (varValue[p] == ')') {
								charString++;
							}
						}
						if (varValue[0] == clica && varValue[2] == clica && strlen(varValue) == 3) {
							value = varValue[1];
							sprintf(String, printing, value);
							sprintf(finalString, "%s%s", finalString, String);
						}
						else {
							if (charString == 2) {
								p = 0;
								char string[300] = "";
								char index[10] = "";
								while (varValue[p] != '('&&varValue[p] != '\0') {
									string[p] = varValue[p];
									p++;
								}
								string[p] = '\0';
								p++;
								h = 0;
								while (varValue[p] != ')'&&varValue[p] != '\0') {
									index[h] = varValue[p];
									p++; h++;
								}
								index[h] = '\0';
								int Index = (int)calcNow(index, result1, result2);

								renamer(string);
								for (h = 0; expressionF[h] != '\0'; h++) {
									string[h] = expressionF[h];
								}
								string[h] = '\0';
								stringVariableToString(string);
								sprintf(String, printing, variableSTring[Index]);
								sprintf(finalString, "%s%s", finalString, String);
								charString = 0;
							}
							else {
								int valu = (int)calcNow(varValue, result1, result2);
								value = valu;
								sprintf(String, printing, value);
								sprintf(finalString, "%s%s", finalString, String);
								value = 0;
							}
						}
					}
					if (specifier == 's') {
						int h = 0;
						renamer(varValue);
						for (h = 0; expressionF[h] != '\0'; h++) {
							varValue[h] = expressionF[h];
						}
						varValue[h] = '\0';
						stringVariableToString(varValue);
						sprintf(String, printing, variableSTring);
						sprintf(finalString, "%s%s", finalString, String);
					}
					if (specifier == 'p') {
						int value = (int)calcNow(varValue, result1, result2);
						sprintf(String, printing, value);
						sprintf(finalString, "%s%s", finalString, String);
						value = 0;
					}
					if (specifier == 'n') {
						int value = (int)calcNow(varValue, result1, result2);
						_set_printf_count_output(1);
						sprintf(String, printing, &value);
						sprintf(finalString, "%s%s", finalString, String);
						_set_printf_count_output(0);
						value = 0;
					}
					i--;
				}
				if (var2Print == 2) {
					j = 0;
					while (!(listText[i - 1] == '%'&&verify4Printf(listText[i]) == 0) && listText[i] != '\0') {
						toPrint[j] = listText[i];
						i++;
						j++;
					}
					toPrint[j] = '\0';
					sprintf(String, "%s", toPrint);
					sprintf(finalString, "%s%s", finalString, String);
					i--;
				}
				if (var2Print == 0) {
					sprintf(String, "%c", listText[i]);
					i++;
					while (i < abs((int)strlen(listText))) {
						sprintf(String, "%s%c", String, listText[i]);
						i++;
					}
					sprintf(finalString, "%s%s", finalString, String);
				}
				var2Print = 0;
			}
		}
		else {
			puts("\n==> Error: The number of specifiers and the number of provided variables is not equal. <==\n");
		}
		stringVariableController(variable, finalString);
	}
	else {
		if (listText[strlen(listText) - 1] == '\"') {
			listText[strlen(listText) - 1] = '\0';
		}
		stringVariableController(variable, listText);
	}
}

double solveNow(char toSolveNow[DIM], double result1, double result2) {
	FILE *fsolveN = NULL;
	char path[DIM] = "";
	sprintf(path, "%s\\temp.txt", atcPath);
	while (fsolveN == NULL) {
		fsolveN = fopen(path, "w");
	}
	double resultFF = 0;
	isFromSolveNow = 1;
	solving = false;
	main_core(toSolveNow, toSolveNow, fsolveN, path, result1, result2, feedbackValidation);
	solving = true;
	sprintf(toSolveNow, "");
	resultFF = resultR;
	isFromSolveNow = 0;
	if (fsolveN != NULL) {
		fclose(fsolveN);
	}
	return resultFF;
}

double atcProg(char exprDev[DIM]) {
	FILE *atcDev = NULL;
	char path[DIM] = "";
	sprintf(path, "%s\\temp.txt", atcPath);
	while (atcDev == NULL) {
		atcDev = fopen(path, "w");
	}
	fputs(exprDev, atcDev);
	fclose(atcDev);
	processTxt(path, rf);
	return resultR;
}

double getValue() {
	verified = 0;
	while (verified == 0) {
		char value[DIM] = "";
		gets_s(value);
		solving = false;
		calcNow(value, 0, 0);
		solving = true;
	}
	return resultR;
}

int atcProgramming(char script[DIM]) {
	runningScript = true;
	char nativeCommands[DIM] = ",print,sprint,get,composecommand,if,else,while,for,";
	char commandCandidate[DIM] = "", getLine[DIM] = "";
	int atcP = 0;
	boolean ifStatus = true;
	isContained("script", script);
	if (script[strEnd] == '\0') {
		puts("\nError: Your script is empty!");
	}
	else {
		if (script[strEnd] == '\n') {
			if (isContained("\n ", script)) {
				while (isContained("\n ", script)) {
					int h = strEnd, k = 0;
					h--;
					while (script[h] == ' ') {
						h++;
						k++;
					}
					while (script[h] != '\0') {
						script[h - k] = script[h];
						h++;
					}
					script[h - k] = '\0';
				}
			}
			if (isContained("\n\t", script)) {
				while (isContained("\n\t", script)) {
					int h = strEnd, k = 0;
					h--;
					while (script[h] == '\t') {
						h++;
						k++;
					}
					while (script[h] != '\0') {
						script[h - k] = script[h];
						h++;
					}
					script[h - k] = '\0';
				}
			}
			isContained("script", script);
			int i = strEnd + 1;
			int j = i;
			int c = 0;
			for (i = strEnd + 1; script[i] != '\0'; i++) {
				script[i - j] = script[i];
			}
			script[i - j] = '\0';
			for (i = 0; i < abs((int)strlen(script)); i++) {
				c = 0;
				j = i;
				while (script[i] != ';'&&script[i] != '\n'&&script[i] != '{'&&c < DIM) {
					getLine[c] = script[i];
					i++; c++;
					if (getLine[0] == 'f'&&getLine[1] == 'o'&&getLine[2] == 'r'&&script[i] == ';') {
						getLine[c] = script[i];
						i++; c++;
					}
				}
				if (c == DIM) {
					getLine[c - 1] = '\0';
					puts("\nPlease be careful with terminators ';'.\n");
					return 0;
				}
				else {
					getLine[c] = '\0';
				}
				c = 0;
				if (verifyLetter(getLine[c])) {
					while (verifyLetter(getLine[c])) {
						commandCandidate[c] = getLine[c];
						c++;
					}
					commandCandidate[c] = '\0';
				}
				char candidate[DIM] = "";
				sprintf(candidate, ",%s,", commandCandidate);
				if (isContained(candidate, nativeCommands)) {
					atcProg(getLine);
					atcP = 1;
					if (isEqual("if", commandCandidate)) {
						ifStatus = returned;
						if (returned == (boolean)true) {
							isContained(getLine, script);
							i = strEnd;
							if (script[i] == '\n') {
								i = i + 2;
							}
							else {
								if (script[i] == '{') {
									i = i + 2;
								}
							}
							char innerIF[DIM] = ""; int kl = 1, kr = 0, f = 0;
							while (kl != kr && script[i] != '\0') {
								if (script[i] == '{') {
									kl++;
								}
								if (script[i] == '}') {
									kr++;
								}
								innerIF[f] = script[i];
								f++; i++;
							}
							f--;
							innerIF[f] = '\0';
							sprintf(innerIF, "%s", innerIF);
							char toATCProgram[DIM] = "";
							sprintf(toATCProgram, "script\n%s", innerIF);
							atcProgramming(toATCProgram);
						}
						else {
							if (script[i] == '\n') {
								i = i + 2;
							}
							else {
								if (script[i] == '{') {
									i = i + 2;
								}
							}
							char innerIF[DIM] = ""; int kl = 1, kr = 0, f = 0;
							while (kl != kr && script[i] != '\0') {
								if (script[i] == '{') {
									kl++;
								}
								if (script[i] == '}') {
									kr++;
								}
								innerIF[f] = script[i];
								f++; i++;
							}
							innerIF[f] = '\0';
						}
					}
					if ((isEqual("else", commandCandidate))) {
						if (ifStatus == (boolean)false) {
							isContained(getLine, script);
							i = strEnd;
							if (script[i] == '\n') {
								i = i + 2;
							}
							else {
								if (script[i] == '{') {
									i = i + 2;
								}
							}
							char innerIF[DIM] = ""; int kl = 1, kr = 0, f = 0;
							while (kl != kr && script[i] != '\0') {
								if (script[i] == '{') {
									kl++;
								}
								if (script[i] == '}') {
									kr++;
								}
								innerIF[f] = script[i];
								f++; i++;
							}
							f--;
							innerIF[f] = '\0';
							sprintf(innerIF, "%s", innerIF);
							char toATCProgram[DIM] = "";
							sprintf(toATCProgram, "script\n%s", innerIF);
							atcProgramming(toATCProgram);
						}
						else {
							if (script[i] == '\n') {
								i = i + 2;
							}
							else {
								if (script[i] == '{') {
									i = i + 2;
								}
							}
							char innerIF[DIM] = ""; int kl = 1, kr = 0, f = 0;
							while (kl != kr && script[i] != '\0') {
								if (script[i] == '{') {
									kl++;
								}
								if (script[i] == '}') {
									kr++;
								}
								innerIF[f] = script[i];
								f++; i++;
							}
							innerIF[f] = '\0';
						}
					}
					if (isEqual("while", commandCandidate)) {
						replace("while", "if", getLine);
						char saveGetLine[DIM] = "";
						sprintf(saveGetLine, getLine);
						sprintf(getLine, expressionF);
						atcProg(getLine);
						ifStatus = returned;
						while (returned == (boolean)true) {
							isContained(saveGetLine, script);
							i = strEnd;
							if (script[i] == '\n') {
								i = i + 2;
							}
							else {
								if (script[i] == '{') {
									i = i + 2;
								}
							}
							char innerIF[DIM] = ""; int kl = 1, kr = 0, f = 0;
							while (kl != kr && script[i] != '\0') {
								if (script[i] == '{') {
									kl++;
								}
								if (script[i] == '}') {
									kr++;
								}
								innerIF[f] = script[i];
								f++; i++;
							}
							f--;
							innerIF[f] = '\0';
							sprintf(innerIF, "%s", innerIF);
							char toATCProgram[DIM] = "";
							sprintf(toATCProgram, "script\n%s", innerIF);
							atcProgramming(toATCProgram);
							atcProg(getLine);
						}
					}
					if (isEqual("for", commandCandidate)) {
						int f = 4, p = 0;
						char initial[DIM] = "";
						while (getLine[f] != ';'&&getLine[f] != '\0') {
							initial[p] = getLine[f];
							p++;
							f++;
						}
						initial[p] = '\0';
						atcProg(initial);
						char condition[DIM] = "";
						f++; p = 0;
						while (getLine[f] != ';'&&getLine[f] != '\0') {
							condition[p] = getLine[f];
							p++;
							f++;
						}
						condition[p] = '\0';
						f++; p = 0;
						char final[DIM] = "";
						while (getLine[f] != ')'&&getLine[f] != '\0') {
							final[p] = getLine[f];
							p++;
							f++;
						}
						final[p] = '\0';
						char saveGetLine[DIM] = "";
						sprintf(saveGetLine, getLine);
						sprintf(getLine, "if(%s)", condition);
						atcProg(getLine);
						ifStatus = returned;
						while (returned == (boolean)true) {
							isContained(saveGetLine, script);
							i = strEnd;
							if (script[i] == '\n') {
								i = i + 2;
							}
							else {
								if (script[i] == '{') {
									i = i + 2;
								}
							}
							char innerIF[DIM] = ""; int kl = 1, kr = 0, f = 0;
							while (kl != kr && script[i] != '\0') {
								if (script[i] == '{') {
									kl++;
								}
								if (script[i] == '}') {
									kr++;
								}
								innerIF[f] = script[i];
								f++; i++;
							}
							f--;
							innerIF[f] = '\0';
							sprintf(innerIF, "%s", innerIF);
							char toATCProgram[DIM] = "";
							sprintf(toATCProgram, "script\n%s\n%s;", innerIF, final);
							atcProgramming(toATCProgram);
							atcProg(getLine);
						}
					}
				}
				sprintf(commandCandidate, "");
				sprintf(candidate, "");
				if (atcP == 0) {
					atcProg(getLine);
				}
				atcP = 0;
			}
		}
		else {
			puts("\nError: The \"script\" word must be written in the first line and followed a press on the \"Enter\" key.");
		}
	}
	return 0;
}



