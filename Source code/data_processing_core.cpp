

#include "stdafx.h"


double numericalSystems(char numSystem[DIM]){
	double result = 0;
	char system = ' ';
	int i, j = 0;
	system = numSystem[0];
	if (numSystem[1] == '_'){
		numSystem[1] = '-';
	}
	for (i = 1; numSystem[i] != '\0'; i++){
		numSystem[i - 1] = numSystem[i];
		if (numSystem[i - 1] == '.'){
			j++;
			if (j == 2){
				numSystem[i - 1] = '\0';
			}
		}
	}
	numSystem[i - 1] = '\0';

	if (system == 'B'){
		result = binaryToDecimal(numSystem);
	}
	if (system == 'O'){
		result = octalToDecimal(numSystem);
	}
	if (system == 'H'){
		result = hexadecimalToDecimal(numSystem);
	}
	return result;
}

void numSystemsController(){
	FILE *open;
	int state = -1;
	char c[DIM] = "";
	while (state != 1 && state != 0){
		printf("Enable -> 1\nDisable -> 0\n");
		gets(c);
		if (strlen(c) == 1){
			state = atoi(c);
			if (state != 1 && state != 0){
				printf("Error, incorrect choice.\n");
			}
		}
	}
	open = fopen("numSystems.txt", "w");
	fprintf(open, "%d", state);
	fclose(open);
}

void siPrefixController(){
	FILE *open;
	int state = -1;
	char c[DIM] = "";
	while (state != 1 && state != 0){
		printf("Enable -> 1\nDisable -> 0\n");
		gets(c);
		if (strlen(c) == 1){
			state = atoi(c);
			if (state != 1 && state != 0){
				printf("Error, incorrect choice.\n");
			}
		}
	}
	open = fopen("siPrefixes.txt", "w");
	fprintf(open, "%d", state);
	fclose(open);
}

void actualTimeController(){
	FILE *open;
	int state = -1;
	char c[DIM] = "";
	while (state != 1 && state != 0){
		printf("Enable -> 1\nDisable -> 0\n");
		gets(c);
		if (strlen(c) == 1){
			state = atoi(c);
			if (state != 1 && state != 0){
				printf("Error, incorrect choice.\n");
			}
		}
	}
	open = fopen("actualTime.txt", "w");
	fprintf(open, "%d", state);
	fclose(open);
}

double processVariable(char variable[DIM]){
	validVar = 0;
	FILE *open = NULL;
	int i, g, h, y, l = 0, lth = 0, cou = 0;
	double varValue = 0;
	char vari[DIM] = "", va[DIM] = "", value[DIM] = "";
	char *pointer;
	i = 0;
	open = fopen("variables.txt", "a+");
	while (open == NULL&&cou < 10){
		open = fopen("variables.txt", "a+");
		cou++;
	}
	if (cou < 10){
		i = 0;
		for (i = 0; (vari[i] = fgetc(open)) != EOF; i++);
		vari[i] = '\0';
		lth = strlen(vari);
		fclose(open);
		i = 0;
		for (i = 0; vari[i] != '\0'; i++){
			g = 0;
			int j = i;
			while (vari[j] != ' '&&vari[j] != '\0'){
				j++;
			}
			j = j - i;
			if (vari[i] == variable[g] && (i == 0 || vari[i - 1] == '\n')){
				while (vari[i] == variable[g]){
					if (vari[i] == variable[g]){
						va[g] = vari[i];
					}i++; g++;
				}
				if (vari[i] != ' '){
					while (vari[i] != ' '){
						va[g] = vari[i];
						g++; i++;
					}
				}
				va[g] = '\0';
			}
			l = i;
			g = 0;
			for (y = 0; va[y] != '\0'; y++){
				if (va[y] == variable[y]){
					g++;
				}
			}
			vari[lth] = '\0';
			if (g == strlen(va) && strlen(variable) == g&&j == g&&g != 0){
				int space = 0;
				valid = 1; validVar = 1;
				int gh = l;
				while (vari[gh] != '\n'){
					gh++;
				}
				h = gh;
				gh = l + 1;
				y = 0;
				for (gh; gh < h; gh++){
					value[y] = vari[gh];
					if (value[y] == ' '){
						space = 1;
					}
					y++;
				}
				value[y] = '\0';
				if (space == 0){
					resultR = strtod(value, &pointer);
				}
				else{
					char real[DIM] = "", imag[DIM] = "";
					y = 0;
					while (value[y] != ' '){
						real[y] = value[y];
						y++;
					}
					real[y] = '\0';
					y++;
					gh = 0;
					while (value[y] != '\0'){
						imag[gh] = value[y];
						y++; gh++;
					}
					imag[gh] = '\0';
					resultR = strtod(real, &pointer);
					resultI = strtod(imag, &pointer);
					varValue = resultR;
				}
				break;
			}
		}
	}
	return varValue;
}

void variableController(char variable[DIM], double result){
	FILE *open = NULL;
	char va[DIM] = "", vari[DIM] = "";
	int i = 0, f = 0;
	vari[0] = '\0';
	int y = 0, h = 0, k = 0, g = 0;
	open = fopen("variables.txt", "r");
	if (open == NULL){
		open = fopen("variables.txt", "w");
		fclose(open);
	}
	if (open != NULL){
		fclose(open);
	}
	open = NULL;
	while (open == NULL&&i < 100){
		open = fopen("variables.txt", "a+");
		i++;
	}
	if (i < 100){
		for (i = 0; (vari[i] = fgetc(open)) != EOF; i++);
		fclose(open);
		vari[i] = '\0';
		if (vari[0] == '\n'){
			for (i = 0; vari[i + 1] != '\0'; i++){
				vari[i] = vari[i + 1];
			}
			vari[i] = '\0';
		}
		for (i = 0; vari[i] != '\0'; i++){
			g = 0;
			h = i; k = h;
			int j = i;
			while (vari[j] != ' '&&vari[j] != '\0'){
				j++;
			}
			j = j - i;
			int p = 0;
			if (vari[i] == variable[g] && (i == 0 || vari[i - 1] == '\n')){
				f = i;
				while (vari[i] == variable[g]){
					if (vari[i] == variable[g]){
						va[g] = vari[i];
					}g++; i++;
				}
				va[g] = '\0';
				p = strlen(variable);
			}
			g = 0;
			for (y = 0; va[y] != '\0'; y++){
				if (va[y] == variable[y]){
					g++;
				}
			}
			if (g == strlen(va) && strlen(variable) == g&&g == j){
				h = f + p;
				while (vari[h] != '\n'){
					h++;
					p++;
				}
				p++;
				for (f; vari[f + p] != '\0'; f++){
					vari[f] = vari[f + p];
				}
				vari[f] = '\0';
				if (vari[0] == '\n'){
					for (i = 0; vari[i + 1] != '\0'; i++){
						vari[i] = vari[i + 1];
					}
					vari[i] = '\0';
				}
				open = NULL;
				while (open == NULL){
					open = fopen("variables.txt", "w");
				}
				fprintf(open, "%s", vari);
				fclose(open);
				break;
			}
		}
		open = NULL;
		while (open == NULL){
			open = fopen("variables.txt", "a+");
		}
		fprintf(open, "%s %G %G\n", variable, resultR, resultI);
		fclose(open);
	}
}

int variableValidator(char variable[DIM]){
	int validate = 0, i = 0, h = -1, abc = 0, j = 0, k = 0, sD = 0;
	char variableT[DIM], varLetters[DIM] = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm";
	double arith = 0, func = 0;
	for (k = 0; variable[k] != '\0'; k++){
		for (i = 0; varLetters[i] != '\0'; i++){
			if (variable[k] == varLetters[i]){
				j++;
				break;
			}
		}
	}
	if (j != strlen(variable) || j == 0 && strlen(variable) == 0){
		h = 0;
		return h;
	}
	revariable[0] = '\0';

	FILE *var = NULL, *var1 = NULL;
	i = 0;
	abc = strlen(variable);
	valid = 0;
	for (i = 0; variable[i] != '\0'; i++){
		if (i == 0 && (variable[i] == 's' || variable[i] == 'c' || variable[i] == 't' || variable[i] == 'a' || variable[i] == 'l' || variable[i] == 'r' || variable[i] == 'q' || variable[i] == 'g' || variable[i] == 'd')){
			if (variable[i] == 's'){
				revariable[i] = 'p';
			}
			if (variable[i] == 'c'){
				revariable[i] = 'h';
			}
			if (variable[i] == 't'){
				revariable[i] = 'j';
			}
			if (variable[i] == 'a'){
				revariable[i] = 'k';
			}
			if (variable[i] == 'l'){
				revariable[i] = 'z';
			}
			if (variable[i] == 'r'){
				revariable[i] = 'v';
			}
			if (variable[i] == 'q'){
				revariable[i] = 'n';
			}
			if (variable[i] == 'g'){
				revariable[i] = 'm';
			}
			if (variable[i] == 'd'){
				revariable[i] = 'G';
			}
			h = 1;
		}
		else{
			if (variable[i] == 'i' || variable[i] == 'e' || variable[i] == 'x' || variable[i] == 'b' || variable[i] == 'D'){
				if (variable[i] == 'i'){
					revariable[i] = 'o';
				}
				if (variable[i] == 'e'){
					revariable[i] = 'w';
				}
				if (variable[i] == 'x'){
					revariable[i] = 'y';
				}
				if (variable[i] == 'b'){
					revariable[i] = 'u';
				}
				if (variable[i] == 'D'){
					revariable[i] = 'T';
					sD = 1;
				}
				h = 1;
			}
			else{
				if (i == 0 && (variable[i] == 'B' || variable[i] == 'O' || variable[i] == 'H' || variable[i] == 'P')){
					if (variable[i] == 'B'){
						revariable[i] = 'N';
					}
					if (variable[i] == 'O'){
						revariable[i] = 'M';
					}
					if (variable[i] == 'H'){
						revariable[i] = 'V';
					}
					if (variable[i] == 'P'){
						revariable[i] = 'I';
					}
					h = 1;
				}
				else{
					if (variable[i] == 'A' || variable[i] == 'B' || variable[i] == 'C' || variable[i] == 'E' || variable[i] == 'F' || variable[i] == 'P'){
						if (variable[i] == 'A'){
							revariable[i] = 'Q';
						}
						if (variable[i] == 'B'){
							revariable[i] = 'W';
						}
						if (variable[i] == 'C'){
							revariable[i] = 'R';
						}
						if (variable[i] == 'E'){
							revariable[i] = 'Y';
						}
						if (variable[i] == 'F'){
							revariable[i] = 'U';
						}
						if (variable[i] == 'P'){
							revariable[i] = 'S';
						}
						h = 1;
					}
					else{
						revariable[i] = variable[i];
					}
				}
			}
		}
	}

	revariable[i] = '\0';
	i = 0;

	variable[abc] = '\0';
	processVariable(variable);
	variable[abc] = '\0';
	arith = arithSolver(variable, 0);
	if ((variable[0] == 'E' || variable[0] == 'B' || variable[0] == 'O' || variable[0] == 'H' || variable[0] == 'P' || variable[0] == 'x') && variable[1] == '='){
		arith = 10;
	}
	variable[abc] = '\0';
	for (i = 0; variable[i] != '\0'; i++){
		variableT[i] = variable[i];
	}
	variableT[i] = '?'; variableT[i + 1] = '\0';
	char testPrefix[DIM] = "";
	for (i = 0; variable[i] != '\0'; i++){
		testPrefix[i] = variable[i];
	}
	testPrefix[i] = '\0';
	double prefix = 0;
	if (testPrefix[0] == 'P'){
		testPrefix[0] = '1';
		for (i = 1; testPrefix[i] != '\0'; i++){
			testPrefix[i] = testPrefix[i - 1];
		}
		testPrefix[i] = '\0';
		prefix = arithSolver(testPrefix, 0);
	}
	func = functionProcessor(variableT, 0.3, 1.0, 0);
	variable[abc] = '\0';
	processVariable(variable);
	if (h == 1 && valid == 0 && arith == 0 && func == 0 && prefix == 0 && sD == 0){
		processVariable(revariable);
		if (valid == 0){
			i = 0;
			FILE *var1 = NULL;
			if (var1 != NULL){
				fclose(var1);
			}
			var1 = NULL;
			while (var1 == NULL&&i < 100){
				var1 = fopen("renamedVar.txt", "a+");
				i++;
			}
			if (i < 100){
				fprintf(var1, "%s %s\n", variable, revariable);
				fclose(var1);
				fclose(var1);
			}
			i = 0;
		}
	}
	else{
		if (h == 1 && valid == 0 && (arith != 0 || func != 0 || prefix != 0 || sD != 0)){
			h = 2;
			sD = 0;
		}
	}
	return h;
}

int prefDet(double n, char path[DIM]){
	int y = 0;
	if (n < 0){
		n = n*-1;
		y = 1;
	}
	int a = 0;
	double result = 0;
	FILE *open;
	open = fopen(path, "a+");
	if (path[0] == 'h'&&path[1] == 'i'&&path[2] == 's'&&path[3] == 't'&&path[4] == 'o'&&path[5] == 'r'&&path[6] == 'y'&&path[7] == '.'&&path[8] == 't'&&path[9] == 'x'&&path[10] == 't'){
		a = 1;
	}

	if (n < 1E-21){
		result = n / 1E-24;
		if (y == 1){
			result = result*-1;
		}
		fprintf(open, "=%Gy (yocto-)\n", result);
		if (a == 1){
			printf("=%Gy (yocto-)\n", result);
		}
		fclose(open);
		return 0;
	}
	if (n < 1E-18){
		result = n / 1E-21;
		if (y == 1){
			result = result*-1;
		}
		fprintf(open, "=%Gz (zepto-)\n", result);
		if (a == 1){
			printf("=%Gz (zepto-)\n", result);
		}
		fclose(open);
		return 0;
	}
	if (n < 1E-15){
		result = n / 1E-18;
		if (y == 1){
			result = result*-1;
		}
		fprintf(open, "=%Ga (atto-)\n", result);
		if (a == 1){
			printf("=%Ga (atto-)\n", result);
		}
		fclose(open);
		return 0;
	}
	if (n < 1E-12){
		result = n / 1E-15;
		if (y == 1){
			result = result*-1;
		}
		fprintf(open, "=%Gf (femto-)\n", result);
		if (a == 1){
			printf("=%Gf (femto-)\n", result);
		}
		fclose(open);
		return 0;
	}
	if (n < 1E-9){
		result = n / 1E-12;
		if (y == 1){
			result = result*-1;
		}
		fprintf(open, "=%Gp (pico-)\n", result);
		if (a == 1){
			printf("=%Gp (pico-)\n", result);
		}
		fclose(open);
		return 0;
	}
	if (n < 1E-6){
		result = n / 1E-9;
		if (y == 1){
			result = result*-1;
		}
		fprintf(open, "=%Gn (nano-)\n", result);
		if (a == 1){
			printf("=%Gn (nano-)\n", result);
		}
		fclose(open);
		return 0;
	}
	if (n < 1E-3){
		result = n / 1E-6;
		if (y == 1){
			result = result*-1;
		}
		fprintf(open, "=%G� (micro-)\n", result);
		if (a == 1){
			printf("=%G%c (micro-)\n", result, 230);
		}
		fclose(open);
		return 0;
	}
	if (n < 1E-2){
		result = n / 1E-3;
		if (y == 1){
			result = result*-1;
		}
		fprintf(open, "=%Gm (milli-)\n", result);
		if (a == 1){
			printf("=%Gm (milli-)\n", result);
		}
		fclose(open);
		return 0;
	}
	if (n < 1E-1){
		result = n / 1E-2;
		if (y == 1){
			result = result*-1;
		}
		fprintf(open, "=%Gc (centi-)\n", result);
		if (a == 1){
			printf("=%Gc (centi-)\n", result);
		}
		fclose(open);
		return 0;
	}

	if (n < 1E1){
		result = n / 1E-1;
		if (y == 1){
			result = result*-1;
		}
		fprintf(open, "=%Gd (deci-)\n", result);
		if (a == 1){
			printf("=%Gd (deci-)\n", result);
		}
		fclose(open);
		return 0;
	}
	if (n < 1E2){
		result = n / 1E1;
		if (y == 1){
			result = result*-1;
		}
		fprintf(open, "=%Gda (deca-)\n", result);
		if (a == 1){
			printf("=%Gda (deca-)\n", result);
		}
		fclose(open);
		return 0;
	}
	if (n < 1E3){
		result = n / 1E2;
		if (y == 1){
			result = result*-1;
		}
		fprintf(open, "=%Gh (hecto-)\n", result);
		if (a == 1){
			printf("=%Gh (hecto-)\n", result);
		}
		fclose(open);
		return 0;
	}
	if (n < 1E6){
		result = n / 1E3;
		if (y == 1){
			result = result*-1;
		}
		fprintf(open, "=%Gk (kilo-)\n", result);
		if (a == 1){
			printf("=%Gk (kilo-)\n", result);
		}
		fclose(open);
		return 0;
	}
	if (n < 1E9){
		result = n / 1E6;
		if (y == 1){
			result = result*-1;
		}
		fprintf(open, "=%GM (mega-)\n", result);
		if (a == 1){
			printf("=%GM (mega-)\n", result);
		}
		fclose(open);
		return 0;
	}
	if (n < 1E12){
		result = n / 1E9;
		if (y == 1){
			result = result*-1;
		}
		fprintf(open, "=%GG (giga-)\n", result);
		if (a == 1){
			printf("=%GG (giga-)\n", result);
		}
		fclose(open);
		return 0;
	}
	if (n < 1E15){
		result = n / 1E12;
		if (y == 1){
			result = result*-1;
		}
		fprintf(open, "=%GT (tera-)\n", result);
		if (a == 1){
			printf("=%GT (tera-)\n", result);
		}
		fclose(open);
		return 0;
	}
	if (n < 1E18){
		result = n / 1E15;
		if (y == 1){
			result = result*-1;
		}
		fprintf(open, "=%GP (peta-)\n", result);
		if (a == 1){
			printf("=%GP (peta-)\n", result);
		}
		fclose(open);
		return 0;
	}
	if (n < 1E21){
		result = n / 1E18;
		if (y == 1){
			result = result*-1;
		}
		fprintf(open, "=%GE (exa-)\n", result);
		if (a == 1){
			printf("=%GE (exa-)\n", result);
		}
		fclose(open);
		return 0;
	}
	if (n < 1E24){
		result = n / 1E21;
		if (y == 1){
			result = result*-1;
		}
		fprintf(open, "=%GZ (zetta-)\n", result);
		if (a == 1){
			printf("=%GZ (zetta-)\n", result);
		}
		fclose(open);
		return 0;
	}
	if (n >= 1E24){
		result = n / 1E24;
		if (y == 1){
			result = result*-1;
		}
		fprintf(open, "=%GY (yotta-)\n", result);
		if (a == 1){
			printf("=%GY (yotta-)\n", result);
		}
		fclose(open);
		return 0;
	}
}

double convertToNumber(char number[DIM]){
	int i = 0, j = 0, num = 0, k = 0, l = 0, sig = 1, h = 0, m = 0, f = 0;
	char nu[DIM] = "";
	double result = 0, exp = 0;
	for (h = 0; number[h] != '\0'; h++){
		if (number[h] == 'E'){
			m = h;
			h++;
			f = 0;
			if (number[h] == '-'){
				sig = -1;
				h++;
			}
			while (number[h] != '\0'){
				nu[f] = number[h];
				f++; h++;
			}
			nu[f] = '\0';
			exp = convertToNumber(nu);
			number[m] = '.';
			number[m + 1] = '0';
			number[m + 2] = '\0';
		}
	}

	i = 0;
	while (number[i] != '.'&&number[i] != '\0'){
		i++;
	}
	i--;
	j = i;
	k = i;
	i++;
	while (number[i] != '\0'){
		i++;
	}
	l = strlen(number) - j - 4;
	for (i = 0; j >= 0; i++){
		nu[0] = number[i];
		nu[1] = '.';
		nu[2] = '0';
		nu[3] = '\0';
		num = atoi(nu);
		result = result + num*pot(10.0, j, 1);
		j--;
	}
	k = k + 2;
	i = 1;
	for (k; i <= l; k++){
		nu[0] = number[k];
		nu[1] = '.';
		nu[2] = '0';
		nu[3] = '\0';
		num = atoi(nu);
		result = result + num*pot(10.0, i*-1, 1);
		i++;
	}

	result = result*pot(10.0, exp*sig, 1);
	return result;
}

int isToWrite(char arith[DIM]){
	char noAnswer[16] = "NO_ANSWERS_FILE";
	int h = 0;
	if (noAnswer[h] == arith[h]){
		while (noAnswer[h] == arith[h]){
			h++;
		}
		h--;
		if (h == strlen(arith) && strlen(arith) == strlen(noAnswer)){
			return 0;
		}
	}
	return 1;
}

void renamer(char expression[DIM]){
	expressionF[0] = '\0';
	char varLetters[DIM] = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm", varToRename[DIM] = "";
	int j = 0, k = 0, sd = 0, i = 0;
	for (k = 0; expression[k] != '\0'; k++){
		for (i = 0; varLetters[i] != '\0'; i++){
			if (expression[k] == varLetters[i]){
				varToRename[j] = expression[k];
				j++;
				break;
			}
		}
		if (j > 0 && expression[k] != varLetters[i] && expression[k] != '\0'){
			varToRename[j] = '\0';
			varRename[0] = '\0';
			variableRenamer(varToRename);
			varToRename[0] = '\0';
			sd = k - j;
			j = 0;
			while (varRename[j] != '\0'){
				expression[sd] = varRename[j];
				j++; sd++;
			}
			j = 0;
		}

	}
	for (i = 0; expression[i] != '\0'&&i < strlen(expression); i++){
		expressionF[i] = expression[i];
	}
	expressionF[i] = '\0';
}

double prefToNumber(char prefix){
	double result = 0;
	if (prefix == 'Y'){
		result = pow(10.0, 24.0);
		return result;
	}
	if (prefix == 'Z'){
		result = pow(10.0, 21.0);
		return result;
	}
	if (prefix == 'E'){
		result = pow(10.0, 18.0);
		return result;
	}
	if (prefix == 'P'){
		result = pow(10.0, 15.0);
		return result;
	}
	if (prefix == 'T'){
		result = pow(10.0, 12.0);
		return result;
	}
	if (prefix == 'G'){
		result = pow(10.0, 9.0);
		return result;
	}
	if (prefix == 'M'){
		result = pow(10.0, 6.0);
		return result;
	}
	if (prefix == 'k'){
		result = pow(10.0, 3.0);
		return result;
	}
	if (prefix == 'h'){
		result = pow(10.0, 2.0);
		return result;
	}
	if (prefix == 'D'){
		result = pow(10.0, 1.0);
		return result;
	}
	if (prefix == 'd'){
		result = pow(10.0, -1.0);
		return result;
	}
	if (prefix == 'c'){
		result = pow(10.0, -2.0);
		return result;
	}
	if (prefix == 'm'){
		result = pow(10.0, -3.0);
		return result;
	}
	if (prefix == 'u'){
		result = pow(10.0, -6.0);
		return result;
	}
	if (prefix == 'n'){
		result = pow(10.0, -9.0);
		return result;
	}
	if (prefix == 'p'){
		result = pow(10.0, -12.0);
		return result;
	}
	if (prefix == 'f'){
		result = pow(10.0, -15.0);
		return result;
	}
	if (prefix == 'a'){
		result = pow(10.0, -18.0);
		return result;
	}
	if (prefix == 'z'){
		result = pow(10.0, -21.0);
		return result;
	}
	if (prefix == 'y'){
		result = pow(10.0, -24.0);
		return result;
	}
	return result;
}

void variableRenamer(char variable[DIM]){
	varRename[0] = '\0';

	char vari[DIM] = "";
	int i = 0, j = 0;
	FILE *open = NULL;
	while (open == NULL&&i < 50){
		open = fopen("renamedVar.txt", "a+");
		i++;
	}
	if (open != NULL){
		for (i = 0; (vari[i] = fgetc(open)) != EOF; i++);
		vari[i] = '\0';
		fclose(open);
		for (i = 0; vari[i] != '\0'; i++){
			j = 0;
			if (variable[j] == vari[i] && (i == 0 || vari[i - 1] == '\n')){
				while (variable[j] == vari[i] && vari[i] != '\0'){
					j++; i++;
				}
				if (strlen(variable) == j){
					if (variable[j] == '\0'&&vari[i] == ' '){
						valRenamedVar = 1;
						i++;
						j = 0;
						while (vari[i] != '\n'&&vari[i] != '\0'){
							varRename[j] = vari[i];
							j++; i++;
						}
						varRename[j] = '\0';
					}
				}
			}
		}
	}
}

void pathNameToPath(char pathName[DIM]){
	FILE *open = NULL;
	int i = 0, j = 0, k = 0;
	char data[DIM] = "";
	pathNAme[0] = '\0';
	open = fopen("pathName.txt", "r");
	if (open == NULL){
		puts("\n==> No path abbreviation created! <==\n");
	}
	else{
		for (i = 0; (data[i] = fgetc(open)) != EOF; i++);
		fclose(open);
		for (i = 0; data[i] != '\0'; i++){
			if (data[i] == pathName[j] && (data[i - 1] == '\n' || i == 0)){
				while (data[i] == pathName[j]){
					j++;
					i++;
				}
				if (j == strlen(pathName) && data[i] == ' '){
					i++;
					while (data[i] != '\n'){
						pathNAme[k] = data[i];
						k++; i++;
					}
					pathNAme[k] = '\0';

				}

			}
			else{
				j = 0;
			}
		}
		if (strlen(pathNAme) == 0){
			puts("\n==> This path abbreviation not exist! <==\n");
		}
	}
}

void pathNameController(char pathName[DIM], char path[DIM]){
	FILE *save = NULL;
	while (save == NULL){
		save = fopen("pathName.txt", "a+");
	}
	char data[DIM] = "", paName[DIM] = "";
	int i = 0, j = 0, k = 0, y = 0, w = 0, l = 0;
	for (i = 0; (data[i] = fgetc(save)) != EOF; i++);
	data[i] = '\0';
	for (i = 0; data[i] != '\0'; i++){
		if (data[i] == pathName[j] && (data[i - 1] == '\n' || i == 0)){
			y = i;
			while (data[i] == pathName[j]){
				j++;
				i++;
			}
			if (j == strlen(pathName) && data[i] == ' '){
				i++;
				while (data[i] != '\n'){
					paName[k] = data[i];
					k++; i++;
				}
				paName[k] = '\0';
				w = strlen(pathName) + strlen(paName) + 3;
				for (l = y; data[l + w] != '\0'; l++){
					data[l] = data[l + w];

				}
				data[l] = '\0';
				fclose(save);
				save = fopen("pathName.txt", "w");
				fputs(data, save);
				fclose(save);
			}

		}
		else{
			j = 0;
		}
	}
	save = fopen("pathName.txt", "a+");
	fprintf(save, "%s %s\n", pathName, path);
	fclose(save);
}

void stringVariableToString(char stringVariable[DIM]){
	FILE *open = NULL;
	int i = 0, j = 0, k = 0;
	char data[DIM] = "";
	variableSTring[0] = '\0';
	open = fopen("stringVariable.txt", "r");
	if (open == NULL){
		puts("\n==> No string variable created! <==\n");
	}
	else{
		for (i = 0; (data[i] = fgetc(open)) != EOF; i++);
		data[i] = '\0';
		fclose(open);
		for (i = 0; data[i] != '\0'; i++){
			j = 0;
			if (data[i] == stringVariable[j] && (data[i - 1] == '\n' || i == 0) && j == 0){
				while (data[i] == stringVariable[j]){
					j++;
					i++;
				}
				if (j == strlen(stringVariable) && data[i] == '\n'){


					TCHAR NPath[MAX_PATH];
					GetCurrentDirectory(MAX_PATH, NPath);
					char directory[MAX_PATH] = "";
					wcstombs(directory, NPath, wcslen(NPath) + 1);
					sprintf(directory, "%s\\Strings\\%s.txt", directory, stringVariable);

					open = fopen(directory, "a+");
					for (k = 0; (variableSTring[k] = fgetc(open)) != EOF; k++);
					variableSTring[k] = '\0';
					fclose(open);

				}
			}
		}
		if (strlen(variableSTring) == 0){
			puts("\n==> This string variable doesn't exist! <==\n");
		}
	}
}

void stringVariableController(char stringVariable[DIM], char string[DIM]){
	FILE *save = NULL;
	while (save == NULL){
		save = fopen("stringVariable.txt", "a+");
	}
	char data[DIM] = "", vaString[DIM] = "";
	int i = 0, j = 0, k = 0, y = 0, w = 0, l = 0;
	for (i = 0; (data[i] = fgetc(save)) != EOF; i++);
	data[i] = '\0';
	for (i = 0; data[i] != '\0'; i++){
		if (data[i] == stringVariable[j] && (data[i - 1] == '\n' || i == 0)){
			y = i;
			while (data[i] == stringVariable[j]){
				j++;
				i++;
			}
			if (j == strlen(stringVariable) && data[i] == '\n'){
				w = strlen(stringVariable) + 3;
				for (l = y; data[l + w] != '\0'; l++){
					data[l] = data[l + w];

				}
				data[l] = '\0';
				fclose(save);
				save = fopen("stringVariable.txt", "w");
				fputs(data, save);
				fclose(save);
			}

		}
		else{
			j = 0;
		}
	}
	save = fopen("stringVariable.txt", "a+");
	fprintf(save, "%s\n", stringVariable);
	fclose(save);

	TCHAR NPath[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, NPath);
	char directory[MAX_PATH] = "";
	wcstombs(directory, NPath, wcslen(NPath) + 1);
	sprintf(directory, "%s\\Strings\\%s.txt", directory, stringVariable);
	save = fopen(directory, "w");
	if (save != NULL){
		fprintf(save, "%s\n", string);
		fclose(save);
	}
}

int firstLetterVariable(char letter){
	char letters[100] = "QWRTYUISGJKLZXVNMwyuofhjkzvnmp";
	int i = 0;
	for (i = 0; i < strlen(letters); i++){
		if (letter == letters[i]){
			return 1;
		}
	}
	return 0;
}

int letterVariables(char letter){
	char letters[100] = "QWRTYUIOSGHJKLZXVNMqwrtyuopasdfghjklzcvnm";
	int i = 0;
	for (i = 0; i < strlen(letters); i++){
		if (letter == letters[i]){
			return 1;
		}
	}
	return 0;
}

int verifyLetter(char letter){
	char letters[DIM] = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm";
	int i = 0;
	for (i = 0; i < strlen(letters); i++){
		if (letter == letters[i]){
			return 1;
		}
	}
	return 0;
}

int verifyNumber(char number){
	char numbers[DIM] = "0123456789";
	int i = 0;
	for (i = 0; i < strlen(numbers); i++){
		if (number == numbers[i]){
			return 1;
		}
	}
	return 0;
}

int verifyNumerical(char number){
	char numbers[DIM] = "_-.0123456789ABCDEF";
	int i = 0;
	for (i = 0; i < strlen(numbers); i++){
		if (number == numbers[i]){
			return 1;
		}
	}
	return 0;
}

int verify4Printf(char chars){
	char printfChars[DIM] = "0123456789diuoxXfFeEgGaAcspn%-+#*.hljztL\"";
	int i = 0;
	for (i = 0; i < strlen(printfChars); i++){
		if (chars == printfChars[i]){
			return 1;
		}
	}
	return 0;
}

int verifySpecifier(char chars){
	char printfChars[DIM] = "diuoxXfFeEgGaAcsp";
	int i = 0;
	for (i = 0; i < strlen(printfChars); i++){
		if (chars == printfChars[i]){
			return 1;
		}
	}
	return 0;
}

void variableToMultiply(char expression[DIM]){
	int i = 0, j = 0, k = 0, v = -7, u = 0, d = 0, l = 0;
	char variable[DIM] = "", saveVariable[DIM] = "";
	while (expression[i] != '\0'){
		v = -7;
		if (verifyLetter(expression[i]) == 1 && (verifyLetter(expression[i - 1]) == 0 || i == 0)){
			j = 0;
			u = i;
			validVar = 0;
			while (verifyLetter(expression[i]) == 1){
				variable[j] = expression[i];
				variable[j + 1] = '\0';
				for (d = 0; variable[d] != '\0'; d++){
					saveVariable[d] = variable[d];
				}
				saveVariable[d] = '\0';
				processVariable(variable);
				if (validVar == 0){
					variableRenamer(variable);
					for (k = 0; varRename[k] != '\0'; k++){
						variable[k] = varRename[k];
					}
					variable[k] = '\0';

					processVariable(variable);
				}
				for (d = 0; saveVariable[d] != '\0'; d++){
					variable[d] = saveVariable[d];
				}
				variable[d] = '\0';
				if (validVar == 1){
					l = strlen(expression);
					v = i;
				}
				j++; i++;
			}
			if (v > 0){
				k = l;
				expression[k + 1] = '\0';
				for (k; k - 1 > v; k--){
					expression[k] = expression[k - 1];
				}
				if (verifyNumber(expression[k + 1]) == 1 || verifyLetter(expression[k + 1]) == 1){
					expression[k] = '*';
				}
				else{
					for (k; expression[k + 1] != '\0'; k++){
						expression[k] = expression[k + 1];
					}
					expression[k] = '\0';
				}
				i = v;
			}



		}
		i++;
	}
	int y = 0;
	for (y = 0; expression[y] != '\0'; y++){
		expressionF[y] = expression[y];
	}
	expressionF[y] = '\0';
}

void toMultiply(char expression[DIM], double result1, double result2){
	int i = 0, verify = 0, verifys = 0, j = 0;
	char value[DIM] = "";
	while (expression[i] != '\0'){
		if (expression[i] == '+'&&expression[i + 1] == '0'&&expression[i + 2] == '\0'){
			value[j] = expression[i];
			value[j + 1] = '0'; value[j + 2] = '\0';
			j++; i = i + 2;
		}
		else{
			if (verifyNumber(expression[i]) == 1){
				while (verifyNumber(expression[i]) == 1 && expression[i] != '\0' || expression[i] == 'i'&&expression[i - 1] == '1'){
					value[j] = expression[i];
					value[j + 1] = '+'; value[j + 2] = '0'; value[j + 3] = '\0';
					j++; i++;
				}
			}

			else{
				if (verifyLetter(expression[i - 1]) == 0 && firstLetterVariable(expression[i]) == 1){
					while (verifyLetter(expression[i]) == 1 && expression[i] != '\0'){
						value[j] = expression[i];
						j++; i++;
					}
					value[j + 1] = '+'; value[j + 2] = '0'; value[j + 3] = '\0';
					synTest = 0;
					verify = dataVerifier(value, result1, result2, 0, verify);

				}
				else{
					if (verifyLetter(expression[i - 1]) == 0 && firstLetterFunction(expression[i]) == 1){
						value[j] = expression[i];
						value[j + 1] = '+'; value[j + 2] = '0'; value[j + 3] = '\0';
						j++; i++;
						synTest = 0;
						verify = dataVerifier(value, result1, result2, 0, verify);

						while (verify == 0 && expression[i] != '\0'){
							if (expression[i] == 'b'){
								value[j] = expression[i];
								j++; i++;
								while ((expression[i] == 'b'&&expression[i + 1] == '(') == false && expression[i] != '\0'){
									value[j] = expression[i];
									j++; i++;
								}
							}
							else{
								if (expression[i] == 'D'){
									value[j] = expression[i];
									j++; i++;
									while ((expression[i] == 'D'&&expression[i + 1] == '(') == false && expression[i] != '\0'){
										value[j] = expression[i];
										j++; i++;
									}
								}
								else{
									value[j] = expression[i];
									value[j + 1] = '+'; value[j + 2] = '0'; value[j + 3] = '\0';
									synTest = 0;
									verify = dataVerifier(value, result1, result2, 0, verify);
									j++; i++;
								}
							}
						}
					}
					else{
						if (verifyLetter(expression[i]) == 0 && verifyNumber(expression[i]) == 0){
							while (verifyLetter(expression[i]) == 0 && verifyNumber(expression[i]) == 0 && expression[i] != '\0'){
								value[j] = expression[i];
								value[j + 1] = '+'; value[j + 2] = '0'; value[j + 3] = '\0';
								j++; i++;
								if (expression[i] == 'i'){
									value[j] = expression[i];
									value[j + 1] = '+'; value[j + 2] = '0'; value[j + 3] = '\0';
									j++; i++;
								}
							}
						}
						else{
							if (expression[i] == 'i'){
								value[j] = expression[i];
								j++; i++;
								value[j] = expression[i];
								value[j + 1] = '\0'; j++;
							}
							else{
								value[j] = expression[i];
								value[j + 1] = '\0';
							}
							synTest = 0;
							verify = dataVerifier(value, result1, result2, 0, verify);

							if (verify == 1 && firstLetterFunction(value[j]) == 0 && verifyLetter(value[j]) == 1 && value[j] != 'i'){
								j++; i++;
								while (verify == 1 && expression[i] != '\0'){
									value[j] = expression[i];
									value[j + 1] = '+'; value[j + 2] = '0'; value[j + 3] = '\0';
									synTest = 0;
									verify = dataVerifier(value, result1, result2, 0, verify);
									j++; i++;
								}
								if (expression[i] != '+'&&expression[i] != '-'&&expression[i] != '*'&&expression[i] != '/'&&expression[i] != '^'&&expression[i] != '\0'){
									j--;
									if (expression[i - 2] != '+'&&expression[i - 2] != '-'&&expression[i - 2] != '*'&&expression[i - 2] != '/'&&expression[i - 2] != '^'){
										value[j] = '*';
										value[j + 1] = '+'; value[j + 2] = '0'; value[j + 3] = '\0';
										j++;
									}
									i--;
								}

							}
							else{
								value[j] = expression[i];
								value[j + 1] = '+'; value[j + 2] = '0'; value[j + 3] = '\0';
								synTest = 0;
								verify = dataVerifier(value, result1, result2, 0, verify);

								if (verify == 0){
									j++; i++;
									while (verify == 0 && expression[i] != '\0'){
										value[j] = expression[i];
										value[j + 1] = '+'; value[j + 2] = '0'; value[j + 3] = '\0';
										synTest = 0;
										verify = dataVerifier(value, result1, result2, 0, verify);
										value[j + 1] = expression[i + 1]; value[j + 2] = '+'; value[j + 3] = '0'; value[j + 4] = '\0';
										int verifyS = dataVerifier(value, result1, result2, 0, verify);
										value[j + 1] = '+'; value[j + 2] = '0'; value[j + 3] = '\0';
										if (verify == verifyS&&verify == 1 && verifyLetter(expression[i + 1]) == 1){
											verify = 0;
										}
										j++; i++;
									}
									if (expression[i] != '+'&&expression[i] != '-'&&expression[i] != '*'&&expression[i] != '/'&&expression[i] != '^'&&expression[i] != '\0'){
										value[j] = '*';
										value[j + 1] = '+'; value[j + 2] = '0'; value[j + 3] = '\0';
										j++;
									}

								}
								else{
									i++;
								}
							}
						}
					}
				}
			}
		}
	}

	for (i = 0; value[i] != '\0'; i++){
		expressionF[i] = value[i];
	}
	expressionF[i] = '\0';
}

int verifyPrefix(char prefix[DIM]){
	char prefixes[DIM] = "Y,Z,E,P,T,G,M,k,h,da,d,c,m,u,n,p,f,a,z,y,";
	int i = 0, j = 0, valid = 1;
	for (i = 0; prefix[i] != '\0'; i++){
		for (j = 0; prefixes[j] != '\0'; j++){
			if (prefix[i] == prefixes[j] && i == 0){
				while (prefix[i] == prefixes[j]){
					i++; j++;
				}
				if (prefix[i] == '\0'&&prefixes[j] == ','){
					return valid;
				}
				i = 0;
			}
		}
	}
	return 0;
}

int firstLetterFunction(char letter){
	char letters[100] = "castlrqgd";
	int i = 0;
	for (i = 0; i < strlen(letters); i++){
		if (letter == letters[i]){
			return 1;
		}
	}
	return 0;
}

void customFuncRenamer(char variable[DIM]){
	int i = 0;
	for (i = 0; variable[i] != '\0'; i++){
		if (i == 0 && (variable[i] == 's' || variable[i] == 'c' || variable[i] == 't' || variable[i] == 'a' || variable[i] == 'l' || variable[i] == 'r' || variable[i] == 'q' || variable[i] == 'g' || variable[i] == 'd')){
			if (variable[i] == 's'){
				revariable[i] = 'p';
			}
			if (variable[i] == 'c'){
				revariable[i] = 'h';
			}
			if (variable[i] == 't'){
				revariable[i] = 'j';
			}
			if (variable[i] == 'a'){
				revariable[i] = 'k';
			}
			if (variable[i] == 'l'){
				revariable[i] = 'z';
			}
			if (variable[i] == 'r'){
				revariable[i] = 'v';
			}
			if (variable[i] == 'q'){
				revariable[i] = 'n';
			}
			if (variable[i] == 'g'){
				revariable[i] = 'm';
			}
			if (variable[i] == 'd'){
				revariable[i] = 'G';
			}
		}
		else{
			if (variable[i] == 'i' || variable[i] == 'e' || variable[i] == 'x' || variable[i] == 'b' || variable[i] == 'D'){
				if (variable[i] == 'i'){
					revariable[i] = 'o';
				}
				if (variable[i] == 'e'){
					revariable[i] = 'w';
				}
				if (variable[i] == 'x'){
					revariable[i] = 'y';
				}
				if (variable[i] == 'b'){
					revariable[i] = 'u';
				}
				if (variable[i] == 'D'){
					revariable[i] = 'T';
				}
			}
			else{
				if (i == 0 && (variable[i] == 'B' || variable[i] == 'O' || variable[i] == 'H' || variable[i] == 'P')){
					if (variable[i] == 'B'){
						revariable[i] = 'N';
					}
					if (variable[i] == 'O'){
						revariable[i] = 'M';
					}
					if (variable[i] == 'H'){
						revariable[i] = 'V';
					}
					if (variable[i] == 'P'){
						revariable[i] = 'I';
					}
				}
				else{
					if (variable[i] == 'A' || variable[i] == 'B' || variable[i] == 'C' || variable[i] == 'E' || variable[i] == 'F' || variable[i] == 'P'){
						if (variable[i] == 'A'){
							revariable[i] = 'Q';
						}
						if (variable[i] == 'B'){
							revariable[i] = 'W';
						}
						if (variable[i] == 'C'){
							revariable[i] = 'R';
						}
						if (variable[i] == 'E'){
							revariable[i] = 'Y';
						}
						if (variable[i] == 'F'){
							revariable[i] = 'U';
						}
						if (variable[i] == 'P'){
							revariable[i] = 'S';
						}
					}
					else{
						revariable[i] = variable[i];
					}
				}
			}
		}
	}
	revariable[i] = '\0';
}
void manageExpression(char arithTrig[DIM], double result1, double result2, int verify){
	int i = 0, j = 0, s = 0, f = 0;
	char letterScan[DIM] = "";

	for (i = 0; arithTrig[i] != '\0'; i++){
		if (verifyLetter(arithTrig[i]) == 1){
			letterScan[i] = arithTrig[i];
		}
		else{
			letterScan[i] = ' ';
		}
	}
	letterScan[i] = '\0';
	char toTest[DIM] = "";
	int savePosition = 0;
	for (i = 0; letterScan[i] != '\0'; i++){
		if (verifyLetter(letterScan[i]) == 1){
			f = 0;
			savePosition = i;
			while (verifyLetter(letterScan[i]) == 1){
				toTest[f] = letterScan[i];
				i++; f++;
			}
			toTest[f] = '\0';
			char usRFunc[DIM] = "";
			sprintf(usRFunc, "User functions//%s.txt", toTest);
			FILE *test = NULL;
			test = fopen(usRFunc, "r");
			if (test != NULL && (letterScan[savePosition - 4] == 'a'&&letterScan[savePosition - 3] == 't'&&letterScan[savePosition - 2] == 'c'&&letterScan[savePosition - 1] == ' ') == true){
				customFuncRenamer(toTest);
				char renaFunc[DIM] = "";
				for (f = 0; revariable[f] != '\0'; f++){
					renaFunc[f] = revariable[f];
				}
				renaFunc[f] = '\0';
				sprintf(usRFunctions, "%s%s,", usRFunctions, toTest);
				sprintf(usRFuncTrans, "%s%s,", usRFuncTrans, renaFunc);
				int p = 0;
				f = savePosition;
				for (p = 0; renaFunc[p] != '\0'; p++){
					letterScan[f] = renaFunc[p];
					f++;
				}
			}
		}
	}
	for (i = 0; arithTrig[i] != '\0'; i++){
		if (verifyLetter(arithTrig[i]) == 1){
			arithTrig[i] = letterScan[i];
		}
	}
	variableToMultiply(arithTrig);
	for (i = 0; expressionF[i] != '\0'; i++){
		arithTrig[i] = expressionF[i];
	}
	arithTrig[i] = '\0';
	renamer(arithTrig);
	for (i = 0; expressionF[i] != '\0'; i++){
		arithTrig[i] = expressionF[i];
	}
	arithTrig[i] = '\0';
	int needOne = 1;
	while (needOne == 1){
		needOne = 0;
		for (i = 0; arithTrig[i] != '\0'; i++){
			if (arithTrig[i] == 'B' || arithTrig[i] == 'O' || arithTrig[i] == 'H'){
				i++;
				while (verifyNumerical(arithTrig[i]) == 1){
					i++;
				}
				if (arithTrig[i - 1] == '1'&&arithTrig[i] == 'i'){
					j = i;
					i = strlen(arithTrig) + 1;
					while (i > j){
						arithTrig[i] = arithTrig[i - 2];
						i--;
					}
					arithTrig[i] = '*'; arithTrig[i + 1] = '1';
					i = strlen(arithTrig);

				}
			}
		}
		for (i = 0; arithTrig[i] != '\0'; i++){
			if (arithTrig[i] == 'B' || arithTrig[i] == 'O' || arithTrig[i] == 'H'){
				i++;
				while (verifyNumerical(arithTrig[i]) == 1){
					i++;
				}
				if (arithTrig[i - 1] == '1'&&arithTrig[i] == 'i'){
					needOne = 1;
				}
			}
		}
	}
	renamer(arithTrig);
	for (i = 0; expressionF[i] != '\0'; i++){
		arithTrig[i] = expressionF[i];
	}
	arithTrig[i] = '\0';
	needOne = 1;
	while (needOne == 1){
		needOne = 0;
		for (i = 0; arithTrig[i] != '\0'; i++){
			if (verifyLetter(arithTrig[i - 1]) == 1 && arithTrig[i - 1] != '1'&& arithTrig[i - 1] != 'i'&&arithTrig[i - 1] != 'p'&& arithTrig[i] == 'i'&& verifyLetter(arithTrig[i + 1]) == 0 && verifyNumber(arithTrig[i + 1]) == 0){
				j = i;
				i = strlen(arithTrig) + 1;
				while (i > j){
					arithTrig[i] = arithTrig[i - 2];
					i--;
				}
				arithTrig[i] = '*'; arithTrig[i + 1] = '1';
				i = strlen(arithTrig);

			}
		}
		for (i = 0; arithTrig[i] != '\0'; i++){
			if (verifyLetter(arithTrig[i - 1]) == 1 && arithTrig[i - 1] != '1'&& arithTrig[i - 1] != 'i'&&arithTrig[i - 1] != 'p'&& arithTrig[i] == 'i'&& verifyLetter(arithTrig[i + 1]) == 0 && verifyNumber(arithTrig[i + 1]) == 0){
				needOne = 1;
			}
		}
	}
	renamer(arithTrig);
	for (i = 0; expressionF[i] != '\0'; i++){
		arithTrig[i] = expressionF[i];
	}
	arithTrig[i] = '\0';
	int needAst = 1;

	needAst = 1;
	while (needAst == 1){
		needAst = 0;
		for (i = 0; arithTrig[i] != '\0'; i++){
			if (verifyLetter(arithTrig[i - 1]) == 0 && arithTrig[i] == 'e'&&verifyLetter(arithTrig[i + 1]) == 1){
				j = i + 1;
				i = strlen(arithTrig);
				while (i > j){
					arithTrig[i] = arithTrig[i - 1];
					i--;
				}
				arithTrig[i] = '*';
			}
		}

		for (i = 0; arithTrig[i] != '\0'; i++){
			if (verifyLetter(arithTrig[i - 1]) == 0 && arithTrig[i] == 'e'&&verifyLetter(arithTrig[i + 1]) == 1){
				needAst = 1;
			}
		}
	}
	needAst = 1;
	while (needAst == 1){
		needAst = 0;
		for (i = 0; arithTrig[i] != '\0'; i++){
			if (verifyLetter(arithTrig[i - 1]) == 0 && arithTrig[i] == 'p'&& arithTrig[i + 1] == 'i'&&verifyLetter(arithTrig[i + 2]) == 1){
				j = i + 2;
				i = strlen(arithTrig);
				while (i > j){
					arithTrig[i] = arithTrig[i - 1];
					i--;
				}
				arithTrig[i] = '*';
			}
		}

		for (i = 0; arithTrig[i] != '\0'; i++){
			if (verifyLetter(arithTrig[i - 1]) == 0 && arithTrig[i] == 'p'&& arithTrig[i + 1] == 'i'&&verifyLetter(arithTrig[i + 2]) == 1){
				needAst = 1;
			}
		}
	}
	needAst = 1;
	while (needAst == 1){
		needAst = 0;
		for (i = 0; arithTrig[i] != '\0'; i++){
			if (verifyLetter(arithTrig[i - 1]) == 1 && arithTrig[i - 1] != 'b'&&arithTrig[i - 1] != 'D'&&arithTrig[i - 2] != 't'&&arithTrig[i - 3] != 'r' && arithTrig[i] == 'p'&& arithTrig[i + 1] == 'i'&&verifyLetter(arithTrig[i + 2]) == 0){
				j = i;
				i = strlen(arithTrig);
				while (i > j){
					arithTrig[i] = arithTrig[i - 1];
					i--;
				}
				arithTrig[i] = '*';
				i = strlen(arithTrig);

			}
		}

		for (i = 0; arithTrig[i] != '\0'; i++){
			if (verifyLetter(arithTrig[i - 1]) == 1 && arithTrig[i - 1] != 'b'&&arithTrig[i - 1] != 'D'&&arithTrig[i - 2] != 't'&&arithTrig[i - 3] != 'r' && arithTrig[i] == 'p'&& arithTrig[i + 1] == 'i'&&verifyLetter(arithTrig[i + 2]) == 0){
				needAst = 1;
			}
		}
	}
	needAst = 1;
	while (needAst == 1){
		needAst = 0;
		for (i = 0; arithTrig[i] != '\0'; i++){
			if (verifyLetter(arithTrig[i - 1]) == 1 && arithTrig[i] == 'e'&&verifyLetter(arithTrig[i + 1]) == 0){
				j = i;
				i = strlen(arithTrig);
				while (i > j){
					arithTrig[i] = arithTrig[i - 1];
					i--;
				}
				arithTrig[i] = '*';
				i = strlen(arithTrig);
			}
		}

		for (i = 0; arithTrig[i] != '\0'; i++){
			if (verifyLetter(arithTrig[i - 1]) == 1 && arithTrig[i] == 'e'&&verifyLetter(arithTrig[i + 1]) == 0){
				needAst = 1;
			}
		}
	}


	renamer(arithTrig);
	for (i = 0; expressionF[i] != '\0'; i++){
		arithTrig[i] = expressionF[i];
	}
	arithTrig[i] = '\0';
	needAst = 1;
	while (needAst == 1){
		needAst = 0;
		for (i = 0; arithTrig[i] != '\0'; i++){
			if (verifyLetter(arithTrig[i - 1]) == 1 && arithTrig[i] == 'p'&& arithTrig[i + 1] == 'i'&&verifyLetter(arithTrig[i + 2]) == 1){
				if (arithTrig[i - 1] == 'D' || arithTrig[i - 1] == 'b'){
					while (verifyLetter(arithTrig[i]) == 1){
						i--;
					}
					i++;
					int lo = 0;
					char func[DIM] = "";
					while (verifyLetter(arithTrig[i]) == 1 && arithTrig[i] != 'b'&&arithTrig[i] != 'D'){
						func[lo] = arithTrig[i];
						lo++; i++;
					}
					func[lo] = arithTrig[i]; lo++;
					func[lo] = arithTrig[i]; lo++;
					func[lo] = '?'; lo++;
					func[lo] = '\0';
					if (functionProcessor(func, 0, 0, 0) == 0.5){
						i = i + 2;
					}
				}
			}
			if (verifyLetter(arithTrig[i - 1]) == 1 && arithTrig[i] == 'p'&& arithTrig[i + 1] == 'i'&&verifyLetter(arithTrig[i + 2]) == 1){


				j = i;
				i = strlen(arithTrig);
				while (i > j){
					arithTrig[i] = arithTrig[i - 1];
					i--;
				}
				arithTrig[i] = '*';
				j = j + 3;
				i = strlen(arithTrig);
				while (i > j){
					arithTrig[i] = arithTrig[i - 1];
					i--;
				}
				arithTrig[i] = '*';

			}
		}
		for (i = 0; arithTrig[i] != '\0'; i++){
			if (verifyLetter(arithTrig[i - 1]) == 1 && arithTrig[i] == 'p'&& arithTrig[i + 1] == 'i'&&verifyLetter(arithTrig[i + 2]) == 1){
				if (arithTrig[i - 1] == 'D' || arithTrig[i - 1] == 'b'){
					while (verifyLetter(arithTrig[i]) == 1){
						i--;
					}
					i++;
					int lo = 0;
					char func[DIM] = "";
					while (verifyLetter(arithTrig[i]) == 1 && arithTrig[i] != 'b'&&arithTrig[i] != 'D'){
						func[lo] = arithTrig[i];
						lo++; i++;
					}
					func[lo] = arithTrig[i]; lo++;
					func[lo] = arithTrig[i]; lo++;
					func[lo] = '?'; lo++;
					func[lo] = '\0';
					if (functionProcessor(func, 0, 0, 0) == 0.5){
						i = i + 2;
					}
				}
			}

			if (verifyLetter(arithTrig[i - 1]) == 1 && arithTrig[i] == 'p'&& arithTrig[i + 1] == 'i'&&verifyLetter(arithTrig[i + 2]) == 1){
				needAst = 1;
			}
		}
	}

	renamer(arithTrig);
	for (i = 0; expressionF[i] != '\0'; i++){
		arithTrig[i] = expressionF[i];
	}
	arithTrig[i] = '\0';

	needOne = 1;
	while (needOne == 1){
		needOne = 0;
		for (i = 0; arithTrig[i] != '\0'; i++){
			if (verifyLetter(arithTrig[i - 1]) == 0 && arithTrig[i] == 'i'&& verifyLetter(arithTrig[i + 1]) == 1 && arithTrig[i + 1] != 'D'&&arithTrig[i + 1] != 'b'){
				j = i + 1;
				i = strlen(arithTrig);
				while (i > j){
					arithTrig[i] = arithTrig[i - 1];
					i--;
				}
				arithTrig[i] = '*';
				i = strlen(arithTrig);

			}
		}
		for (i = 0; arithTrig[i] != '\0'; i++){
			if (verifyLetter(arithTrig[i - 1]) == 0 && arithTrig[i] == 'i'&& verifyLetter(arithTrig[i + 1]) == 1 && arithTrig[i + 1] != 'D'&&arithTrig[i + 1] != 'b'){
				needOne = 1;
			}
		}
	}
	needOne = 1;
	while (needOne == 1){
		needOne = 0;
		for (i = 0; arithTrig[i] != '\0'; i++){
			if (verifyLetter(arithTrig[i - 1]) == 1 && arithTrig[i - 1] != '1'&&arithTrig[i - 1] != 'p'&& arithTrig[i] == 'i'&& verifyLetter(arithTrig[i + 1]) == 0 && verifyNumber(arithTrig[i + 1]) == 0){
				j = i;
				i = strlen(arithTrig);
				while (i > j){
					arithTrig[i] = arithTrig[i - 1];
					i--;
				}
				arithTrig[i] = '1';
				i = strlen(arithTrig);

			}
		}
		for (i = 0; arithTrig[i] != '\0'; i++){
			if (verifyLetter(arithTrig[i - 1]) == 1 && arithTrig[i - 1] != '1'&&arithTrig[i - 1] != 'p'&& arithTrig[i] == 'i'&& verifyLetter(arithTrig[i + 1]) == 0 && verifyNumber(arithTrig[i + 1]) == 0){
				needOne = 1;
			}
		}
	}
	needAst = 1;
	int mark = 0, mark1 = 0, napier = 0, n = 0, m = 0;
	float isFunc = 0;
	char functionP[DIM] = "";
	while (needAst == 1){
		valRenamedVar = 0;
		for (i = mark1; arithTrig[i] != '\0'; i++){
			if (verifyLetter(arithTrig[i - 1]) == 1 && arithTrig[i] == 'e'&& verifyLetter(arithTrig[i + 1]) == 1 && needAst == 1){
				if (arithTrig[i - 1] == 'D' || arithTrig[i - 1] == 'b'){
					while (verifyLetter(arithTrig[i]) == 1){
						i--;
					}
					i++;
					int lo = 0;
					char func[DIM] = "";
					while (verifyLetter(arithTrig[i]) == 1 && arithTrig[i] != 'b'&&arithTrig[i] != 'D'){
						func[lo] = arithTrig[i];
						lo++; i++;
					}
					func[lo] = arithTrig[i]; lo++;
					func[lo] = arithTrig[i]; lo++;
					func[lo] = '?'; lo++;
					func[lo] = '\0';
					if (functionProcessor(func, 0, 0, 0) == 0.5){
						i = i + 2;
					}
				}
			}
			if (verifyLetter(arithTrig[i - 1]) == 1 && arithTrig[i] == 'e'&& verifyLetter(arithTrig[i + 1]) == 1 && needAst == 1){
				mark1 = i + 1;
				j = i;
				i = strlen(arithTrig);
				int p = j;
				while (verifyLetter(arithTrig[p]) == 1){
					p--;
				}
				if (j != p){
					p++;

					char function[DIM] = "";

					int y = 0;
					while (verifyLetter(arithTrig[p]) == 1){
						function[y] = arithTrig[p];
						p++; y++;

					}
					function[y] = '?'; function[y + 1] = '\0';
					isFunc = functionProcessor(function, 0, 0, 0);
					if (isFunc == 0.5){
						break;
					}
					else{
						function[y] = '\0';
						valRenamedVar = 0;

						n = 0, m = 0;
						m = 0;
						for (n = 0; function[n] != '\0'; n++){
							while (function[n] != 'e'&&function[n] != '\0'){
								functionP[m] = function[n];
								n++; m++;
							}

							functionP[m] = '\0';
							valRenamedVar = 0;
							variableRenamer(functionP);
							if (valRenamedVar == 1){
								isFunc = 0;
								break;
							}
							else{
								functionP[m] = function[n];
								napier = 1;
								m++;
							}
						}
						if (valRenamedVar == 1){
							isFunc = 0;
						}

					}

				}
				if (isFunc == 0 && napier == 0){
					while (i > j){
						arithTrig[i] = arithTrig[i - 1];
						i--;
					}
					arithTrig[i] = '*';
					j = j + 2;
					i = strlen(arithTrig);
					while (i > j){
						arithTrig[i] = arithTrig[i - 1];
						i--;
					}
					arithTrig[i] = '*';

				}
				if (napier == 1){
					n = 0; m = 0;
					for (n = 0; arithTrig[n] != '\0'; n++){

						if (arithTrig[n] == functionP[m]){
							m = 0;
							while (arithTrig[n] == functionP[m]){
								n++; m++;
							}
							int z = strlen(arithTrig), nj = n, nc = 0;
							nc = z;
							if (arithTrig[nj + 1] != '('){
								if ((arithTrig[nj - 3] == 'l'&&arithTrig[nj - 2] == 'o'&&arithTrig[nj - 1] == 'g'&&arithTrig[nj] == 'b') == false && (arithTrig[nj - 2] == 'r'&&arithTrig[nj - 1] == 't'&&arithTrig[nj] == 'D') == false){
									while (nj < nc){
										arithTrig[nc] = arithTrig[nc - 1];
										nc--;
									}

									arithTrig[nj] = '*';
									z = strlen(arithTrig);
									nj = n + 2;
									if (arithTrig[nj - 1] != '('){
										while (nj < z){
											arithTrig[z] = arithTrig[z - 1];
											z--;
										}
										if (arithTrig[z] != '\0'){
											arithTrig[z] = '*';

										}
									}
								}

							}
						}
					}
				}
			}
		}
		for (i = mark; arithTrig[i] != '\0'; i++){
			needAst = 0;
			if (verifyLetter(arithTrig[i - 1]) == 1 && arithTrig[i] == 'e'&& verifyLetter(arithTrig[i + 1]) == 1){
				if (arithTrig[i - 1] == 'D' || arithTrig[i - 1] == 'b'){
					while (verifyLetter(arithTrig[i]) == 1){
						i--;
					}
					i++;
					int lo = 0;
					char func[DIM] = "";
					while (verifyLetter(arithTrig[i]) == 1 && arithTrig[i] != 'b'&&arithTrig[i] != 'D'){
						func[lo] = arithTrig[i];
						lo++; i++;
					}
					func[lo] = arithTrig[i]; lo++;
					func[lo] = arithTrig[i]; lo++;
					func[lo] = '?'; lo++;
					func[lo] = '\0';
					if (functionProcessor(func, 0, 0, 0) == 0.5){
						i = i + 2;
					}
				}
			}
			if (verifyLetter(arithTrig[i - 1]) == 1 && arithTrig[i] == 'e'&&verifyLetter(arithTrig[i + 1]) == 1){
				mark = i + 1;
				needAst = 1;
			}
		}
	}

	renamer(arithTrig);
	for (i = 0; expressionF[i] != '\0'; i++){
		arithTrig[i] = expressionF[i];
	}
	arithTrig[i] = '\0';

	char paTrig[DIM] = "";
	int u = 0;
	for (u = 0; arithTrig[u] != '\0'; u++){
		paTrig[u] = arithTrig[u];
	}
	paTrig[u] = '\0';
	u = 0;
	for (u; paTrig[u] != '\0'; u++){
		if (verifyLetter(paTrig[u]) == 0){
			while (verifyLetter(paTrig[u]) == 0 && paTrig[u] != '\0'){
				u++;
			}
		}
		if (verifyLetter(paTrig[u]) == 1 && firstLetterVariable(paTrig[u]) == 0){
			while (verifyLetter(paTrig[u]) == 1){
				u++;
			}
		}
		if (firstLetterVariable(paTrig[u]) == 1 && firstLetterVariable(paTrig[u - 1]) == 0 && paTrig[u + 1] != 'i'){
			u++;
			while (verifyLetter(paTrig[u]) == 1){
				u++;
			}
			if (paTrig[u] != '*'&&paTrig[u] != '+'&&paTrig[u] != '-'&&paTrig[u] != '/'&&paTrig[u] != '^'&&paTrig[u] != '!'&&paTrig[u] != ')'){
				double check = 0;
				if (verifyLetter(paTrig[u - 1]) == 1){
					int z = u - 1, v = 0;
					char toVal[DIM] = "";
					while (verifyLetter(paTrig[z]) == 1){
						z--;
					}
					z++;
					while (verifyLetter(paTrig[z]) == 1){
						toVal[v] = paTrig[z];
						z++; v++;
					}
					toVal[v] = '?'; toVal[v + 1] = '\0';
					check = functionProcessor(toVal, 0, 0, 0);
				}


				if (check != 0.5){
					arithTrig[u] = '*';
					for (u; paTrig[u] != '\0'; u++){
						arithTrig[u + 1] = paTrig[u];
					}
					arithTrig[u + 1] = '\0';
					u = 0;
					for (u = 0; arithTrig[u] != '\0'; u++){
						paTrig[u] = arithTrig[u];
					}
					paTrig[u] = '\0';
					u = 0;
				}
			}
		}


	}
	needAst = 1;
	while (needAst == 1){
		needAst = 0;
		for (i = 0; arithTrig[i] != '\0'; i++){
			if (verifyLetter(arithTrig[i - 1]) == 0 && arithTrig[i - 1] != '(' && arithTrig[i] == 'i'&&verifyLetter(arithTrig[i + 1]) == 1 && arithTrig[i + 1] != 'D'&& arithTrig[i + 1] != 'b'){
				j = i + 1;
				i = strlen(arithTrig);
				int comp = 0;
				if (verifyNumber(arithTrig[j - 2]) == 0){
					i++;
					comp = 1;
				}
				if (comp == 0){
					while (i > j){
						arithTrig[i] = arithTrig[i - 1];
						i--;
					}
					arithTrig[i] = '*';
				}
				else{
					while (i > j){
						arithTrig[i] = arithTrig[i - 2];
						i--;
					}
					arithTrig[i] = '1'; arithTrig[i + 1] = '*';
				}
			}
		}
		for (i = 0; arithTrig[i] != '\0'; i++){
			if (verifyLetter(arithTrig[i - 1]) == 0 && arithTrig[i - 1] != '('&&arithTrig[i] == 'i'&&verifyLetter(arithTrig[i + 1]) == 1 && arithTrig[i + 1] != 'D'&& arithTrig[i + 1] != 'b'){
				needAst = 1;
			}
		}
	}
	needAst = 1;
	while (needAst == 1){
		needAst = 0;
		for (i = 0; arithTrig[i] != '\0'; i++){
			if ((verifyLetter(arithTrig[i - 1]) == 1 || verifyNumber(arithTrig[i - 1]) == 1) && arithTrig[i - 1] != 'p' && arithTrig[i - 1] != 'D'&& arithTrig[i - 1] != 'b'&& arithTrig[i] == 'i'&&arithTrig[i - 1] != '1'&&arithTrig[i - 1] != '('&&verifyLetter(arithTrig[i + 1]) == 0){

				j = i;
				i = strlen(arithTrig) + 1;
				while (i > j){
					arithTrig[i] = arithTrig[i - 2];
					i--;
				}
				arithTrig[i] = '*'; arithTrig[i + 1] = '1';
				i = strlen(arithTrig);

			}
		}

		for (i = 0; arithTrig[i] != '\0'; i++){
			if ((verifyLetter(arithTrig[i - 1]) == 1 || verifyNumber(arithTrig[i - 1]) == 1) && arithTrig[i - 1] != 'p' && arithTrig[i - 1] != 'D'&& arithTrig[i - 1] != 'b'&& arithTrig[i] == 'i'&&arithTrig[i - 1] != '1'&&arithTrig[i - 1] != '('&&verifyLetter(arithTrig[i + 1]) == 0){
				needAst = 1;
			}
		}
	}
	needAst = 1;
	while (needAst == 1){
		needAst = 0;
		for (i = 0; arithTrig[i] != '\0'; i++){
			if (arithTrig[i - 1] == ')' && arithTrig[i] == 'i'&&verifyLetter(arithTrig[i + 1]) == 0){
				j = i;
				i = strlen(arithTrig) + 1;
				while (i > j){
					arithTrig[i] = arithTrig[i - 2];
					i--;
				}
				arithTrig[i] = '*'; arithTrig[i + 1] = '1';
				i = strlen(arithTrig);

			}
		}

		for (i = 0; arithTrig[i] != '\0'; i++){
			if (arithTrig[i - 1] == ')' && arithTrig[i] == 'i'&&verifyLetter(arithTrig[i + 1]) == 0){
				needAst = 1;
			}
		}
	}

	needAst = 1;
	while (needAst == 1){
		needAst = 0;
		for (i = 0; arithTrig[i] != '\0'; i++){
			if (verifyLetter(arithTrig[i - 1]) == 0 && arithTrig[i] == 'i'&&arithTrig[i + 1] == '('){
				j = i + 1;
				i = strlen(arithTrig);
				int comp = 0;
				if (verifyNumber(arithTrig[j - 2]) == 0){
					i++;
					comp = 1;
				}
				if (comp == 0){
					while (i > j){
						arithTrig[i] = arithTrig[i - 1];
						i--;
					}
					arithTrig[i] = '*';
				}
				else{
					while (i > j){
						arithTrig[i] = arithTrig[i - 2];
						i--;
					}
					arithTrig[i] = '1'; arithTrig[i + 1] = '*';
				}
			}
		}

		for (i = 0; arithTrig[i] != '\0'; i++){
			if (verifyLetter(arithTrig[i - 1]) == 0 && arithTrig[i] == 'i'&&arithTrig[i + 1] == '('){
				needAst = 1;
			}
		}
	}




	renamer(arithTrig);
	for (i = 0; expressionF[i] != '\0'; i++){
		arithTrig[i] = expressionF[i];
	}
	arithTrig[i] = '\0';
	needAst = 1;
	while (needAst == 1){
		needAst = 0;
		for (i = 0; arithTrig[i] != '\0'; i++){
			if (verifyLetter(arithTrig[i - 1]) == 0 && verifyNumber(arithTrig[i - 1]) == 0 && arithTrig[i] == 'i'&& arithTrig[i + 1] != '1' && (verifyLetter(arithTrig[i + 1]) == 1 || verifyNumber(arithTrig[i + 1]) == 1)){
				j = i + 1;
				i = strlen(arithTrig) + 1;
				while (i > j){
					arithTrig[i] = arithTrig[i - 2];
					i--;
				}
				arithTrig[i] = '1'; arithTrig[i + 1] = '*';
			}

		}
		needAst = 0;
		for (i = 0; arithTrig[i] != '\0'; i++){
			if (verifyLetter(arithTrig[i - 1]) == 0 && verifyNumber(arithTrig[i - 1]) == 0 && arithTrig[i] == 'i'&& arithTrig[i + 1] != '1' && (verifyLetter(arithTrig[i + 1]) == 1 || verifyNumber(arithTrig[i + 1]) == 1)){
				needAst = 1;
			}

		}
	}
	needOne = 1;
	while (needOne == 1){
		needOne = 0;
		for (i = 0; arithTrig[i] != '\0'; i++){
			if ((verifyLetter(arithTrig[i - 1]) == 0 || arithTrig[i - 1] == 'D' || arithTrig[i - 1] == 'b') && verifyNumber(arithTrig[i - 1]) == 0 && arithTrig[i] == 'i'&& verifyNumber(arithTrig[i + 1]) == 0 && (verifyLetter(arithTrig[i + 1]) == 0 || arithTrig[i + 1] == 'D' || arithTrig[i + 1] == 'b')){
				j = i;
				i = strlen(arithTrig);
				while (i > j){
					arithTrig[i] = arithTrig[i - 1];
					i--;
				}
				arithTrig[i] = '1';
				i = strlen(arithTrig);

			}
		}
		for (i = 0; arithTrig[i] != '\0'; i++){
			if ((verifyLetter(arithTrig[i - 1]) == 0 || arithTrig[i - 1] == 'D' || arithTrig[i - 1] == 'b') && verifyNumber(arithTrig[i - 1]) == 0 && arithTrig[i] == 'i'&& verifyNumber(arithTrig[i + 1]) == 0 && (verifyLetter(arithTrig[i + 1]) == 0 || arithTrig[i + 1] == 'D' || arithTrig[i + 1] == 'b')){
				needOne = 1;
			}
		}
	}
	needAst = 1;
	while (needAst == 1){
		needAst = 0;
		for (i = 0; arithTrig[i] != '\0'; i++){
			if (arithTrig[i - 1] == '1' && arithTrig[i] == 'i' && (verifyLetter(arithTrig[i + 1]) == 1 && arithTrig[i + 1] != 'D'&&arithTrig[i + 1] != 'b' || verifyNumber(arithTrig[i + 1]) == 1)){
				j = i + 1;
				i = strlen(arithTrig);
				while (i > j){
					arithTrig[i] = arithTrig[i - 1];
					i--;
				}
				arithTrig[i] = '*';
			}
		}

		for (i = 0; arithTrig[i] != '\0'; i++){
			if (arithTrig[i - 1] == '1' && arithTrig[i] == 'i' && (verifyLetter(arithTrig[i + 1]) == 1 && arithTrig[i + 1] != 'D'&&arithTrig[i + 1] != 'b' || verifyNumber(arithTrig[i + 1]) == 1)){
				needAst = 1;
			}
		}
	}

	s = 0;
	for (s = 0; arithTrig[s] != '\0'; s++){
		paTrig[s] = arithTrig[s];
	}
	paTrig[s] = '\0';

	s = 0;

	s = 0;
	for (s; paTrig[s] != '\0'; s++){
		if ((paTrig[s] == 'e'&&paTrig[s + 1] != 'b' || paTrig[s] == 'i'&&paTrig[s - 1] == 'p'&&paTrig[s + 1] != 'b' || paTrig[s] == '1' || paTrig[s] == '2' || paTrig[s] == '3' || paTrig[s] == '4' || paTrig[s] == '5' || paTrig[s] == '6' || paTrig[s] == '7' || paTrig[s] == '8' || paTrig[s] == '9' || paTrig[s] == '0' || paTrig[s] == '.') && (paTrig[s + 1] == '#' || paTrig[s + 1] == 'w' || paTrig[s + 1] == 'y' || paTrig[s + 1] == 'u' || paTrig[s + 1] == 'o' || paTrig[s + 1] == 'p' || paTrig[s + 1] == 'f' || paTrig[s + 1] == 'h' || paTrig[s + 1] == 'j' || paTrig[s + 1] == 'k' || paTrig[s + 1] == 'z' || paTrig[s + 1] == 'x' || paTrig[s + 1] == 'v' || paTrig[s + 1] == 'm' || paTrig[s + 1] == 'Q' || paTrig[s + 1] == 'W' || paTrig[s + 1] == 'R' || paTrig[s + 1] == 'T' || paTrig[s + 1] == 'Y' || paTrig[s + 1] == 'U' || paTrig[s + 1] == 'I' || paTrig[s + 1] == 'S' || paTrig[s + 1] == 'G' || paTrig[s + 1] == 'J' || paTrig[s + 1] == 'K' || paTrig[s + 1] == 'L' || paTrig[s + 1] == 'Z' || paTrig[s + 1] == 'X' || paTrig[s + 1] == 'V' || paTrig[s + 1] == 'N' || paTrig[s + 1] == 'M')){
			s++;
			arithTrig[s] = '*';
			for (s; paTrig[s] != '\0'; s++){
				arithTrig[s + 1] = paTrig[s];
			}
			arithTrig[s + 1] = '\0';
			s = 0;
			for (s = 0; arithTrig[s] != '\0'; s++){
				paTrig[s] = arithTrig[s];
			}
			paTrig[s] = '\0';
			s = 0;
		}
	}
	s = 0;
	for (s; paTrig[s] != '\0'; s++){
		if ((paTrig[s + 1] == 'e'&&paTrig[s] != 'b' || paTrig[s + 1] == 'p'&&paTrig[s + 2] == 'i'&&paTrig[s] != 'b' || paTrig[s + 1] == '1' || paTrig[s + 1] == '2' || paTrig[s + 1] == '3' || paTrig[s + 1] == '4' || paTrig[s + 1] == '5' || paTrig[s + 1] == '6' || paTrig[s + 1] == '7' || paTrig[s + 1] == '8' || paTrig[s + 1] == '9' || paTrig[s + 1] == '0' || paTrig[s + 1] == '.') && (paTrig[s] == 'q' || paTrig[s] == 'w' || paTrig[s] == 't' || paTrig[s] == 'y' || paTrig[s] == 'u' || paTrig[s] == 'o' || paTrig[s] == 'p' || paTrig[s] == 'a' || paTrig[s] == 'f' || paTrig[s] == 'h' || paTrig[s] == 'j' || paTrig[s] == 'k' || paTrig[s] == 'l' || paTrig[s] == 'z' || paTrig[s] == 'c' || paTrig[s] == 'v' || paTrig[s] == 'n' || paTrig[s] == 'm' || paTrig[s] == 'Q' || paTrig[s] == 'W' || paTrig[s] == 'R' || paTrig[s] == 'T' || paTrig[s] == 'Y' || paTrig[s] == 'U' || paTrig[s] == 'I' || paTrig[s] == 'S' || paTrig[s] == 'G' || paTrig[s] == 'J' || paTrig[s] == 'K' || paTrig[s] == 'L' || paTrig[s] == 'Z' || paTrig[s] == 'X' || paTrig[s] == 'V' || paTrig[s] == 'N' || paTrig[s] == 'M')){
			s++;
			arithTrig[s] = '*';
			for (s; paTrig[s] != '\0'; s++){
				arithTrig[s + 1] = paTrig[s];
			}
			arithTrig[s + 1] = '\0';
			s = 0;
			for (s = 0; arithTrig[s] != '\0'; s++){
				paTrig[s] = arithTrig[s];
			}
			paTrig[s] = '\0';
			s = 0;
		}
	}
	toMultiply(arithTrig, result1, result2);
	for (i = 0; expressionF[i] != '\0'; i++){
		arithTrig[i] = expressionF[i];
	}
	arithTrig[i] = '\0';
	for (i = 0; arithTrig[i] != '\0'; i++){
		expressionF[i] = arithTrig[i];
	}
	expressionF[i] = '\0';
}

void openTxt(){
	char openFile[DIM] = "";
	sprintf(openFile, "notepad.exe %s", expressionF);
	system(openFile);
}

void cls()
{
	HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD coordScreen = { 0, 0 };    // home for the cursor 
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;

	// Get the number of character cells in the current buffer. 

	if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
	{
		return;
	}

	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

	// Fill the entire screen with blanks.

	if (!FillConsoleOutputCharacter(hConsole,        // Handle to console screen buffer 
		(TCHAR) ' ',     // Character to write to the buffer
		dwConSize,       // Number of cells to write 
		coordScreen,     // Coordinates of first cell 
		&cCharsWritten))// Receive number of characters written
	{
		return;
	}

	// Get the current text attribute.

	if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
	{
		return;
	}

	// Set the buffer's attributes accordingly.

	if (!FillConsoleOutputAttribute(hConsole,         // Handle to console screen buffer 
		csbi.wAttributes, // Character attributes to use
		dwConSize,        // Number of cells to set attribute 
		coordScreen,      // Coordinates of first cell 
		&cCharsWritten)) // Receive number of characters written
	{
		return;
	}

	// Put the cursor at its home coordinates.

	SetConsoleCursorPosition(hConsole, coordScreen);
}

bool IsPreviousToWindowsVista()
{
	bool previousToVista = false;

	OSVERSIONINFOEX osversion;
	ZeroMemory(&osversion, sizeof(OSVERSIONINFOEX));
	osversion.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
	if (GetVersionEx((OSVERSIONINFO*)&osversion))
	{
		const DWORD VistaVersion = 6;
		if ((osversion.dwPlatformId == VER_PLATFORM_WIN32_NT) && (osversion.dwMajorVersion < VistaVersion))
		{
			previousToVista = true;
		}
	}

	return previousToVista;
}

void on_start(){
	FILE *open = NULL;
	char onStart[100] = "";
	int Colors = 1, Dimensions = 2, Window = 3;
	open = fopen("onStart.txt", "r");
	if (open != NULL){
		fgets(onStart, 100, open);
		fclose(open);
		if (onStart[0] == 'r'&&onStart[1] == 'e'&&onStart[2] == 's'&&onStart[3] == 'e'&&onStart[4] == 't'&&onStart[5] == 'a'&&onStart[6] == 'l'&&onStart[7] == 'l'&&onStart[8] == '\0'){
			ShellExecute(NULL, _T("open"), _T("C:\\WINDOWS\\system32\\cmd.exe"), _T("/C \"del history.txt&del variables.txt&del renamedVar.txt&del pathName.txt&del predefinedTxt.txt&del calendar.txt&del numSystems.txt&del siPrefixes.txt&del actualTime.txt&del colors.txt&del dimensions.txt&del window.txt&del mode.txt&del onStart.txt&del disable_txt_detector.txt&del stringVariable.txt&rmdir /Q /S Strings&mkdir Strings\""), NULL, SW_SHOW);
			Sleep(1000);
			applySettings(Colors);
			applySettings(Window);
			applySettings(Dimensions);
		}
		if (onStart[0] == 'r'&&onStart[1] == 'e'&&onStart[2] == 's'&&onStart[3] == 'e'&&onStart[4] == 't'&&onStart[5] == 's'&&onStart[6] == 'e'&&onStart[7] == 't'&&onStart[8] == 't'&&onStart[9] == 'i'&&onStart[10] == 'n'&&onStart[11] == 'g'&&onStart[12] == 's'&&onStart[13] == '\0'){
			ShellExecute(NULL, _T("open"), _T("C:\\WINDOWS\\system32\\cmd.exe"), _T("/C \"del numSystems.txt&del siPrefixes.txt&del actualTime.txt&del colors.txt&del dimensions.txt&del window.txt&del mode.txt&del onStart.txt\""), NULL, SW_SHOW);
			Sleep(1000);
			applySettings(Colors);
			applySettings(Window);
			applySettings(Dimensions);
		}
	}

}

int searchExtension(char filename[DIM], char extension[DIM]){
	int i = strlen(filename) - 1, j = strlen(extension) - 1;
	while (extension[j] == filename[i]){
		i--; j--;
	}
	i++; j++;
	if (extension[j] == filename[i] && extension[j] == '.'){
		return 1;
	}
	else{
		return 0;
	}
}

void toSolve(int re){
	FILE *file = NULL;
	file = fopen("disable_txt_detector.txt", "r");
	if (file == NULL){
		char option[30] = "";
		TCHAR NPath[MAX_PATH];
		GetCurrentDirectory(MAX_PATH, NPath);
		char directory[MAX_PATH] = "";
		wcstombs(directory, NPath, wcslen(NPath) + 1);
		sprintf(directory, "%s\\To solve\\", directory);
		int k = 0, numFiles = 0, i = 0;
		DIR *d;
		struct dirent *dir;
		d = opendir(directory);
		char filename[DIM] = "";
		char txtFiles[DIM] = "";
		if (d)
		{
			while ((dir = readdir(d)) != NULL)
			{
				if (dir->d_type == DT_REG)
				{
					sprintf(filename, "%s", dir->d_name);
					if (searchExtension(filename, ".txt") == 1){
						int h = strlen(filename) - 1;
						if ((filename[h - 10] == 'a'&& filename[h - 9] == 'n'&&filename[h - 8] == 's'&&filename[h - 7] == 'w'&&filename[h - 6] == 'e'&&filename[h - 5] == 'r'&&filename[h - 4] == 's'&&filename[h - 3] == '.'&&filename[h - 2] == 't'&&filename[h - 1] == 'x'&&filename[h] == 't') == false){
							char path[DIM] = "";
							sprintf(path, "%s%s", directory, filename);
							int b = 0, m = 0;
							char addChars[DIM] = "_answers.txt";
							while ((path[b] == '.'&&path[b + 1] == 't'&&path[b + 2] == 'x'&&path[b + 3] == 't') == false){
								b++;
							}
							while (addChars[m] != '\0'){
								path[b] = addChars[m];
								b++; m++;
							}
							path[b] = '\0';
							FILE *open = NULL;
							open = fopen(path, "r");
							if (open == NULL){
								sprintf(txtFiles, "%s\n%s", txtFiles, filename);
								numFiles++;
							}
							else{
								fclose(open);
							}
						}
					}
				}

			}

			for (k = 0; txtFiles[k + 1] != '\0'; k++){
				txtFiles[k] = txtFiles[k + 1];
			}
			txtFiles[k] = '\0';
			closedir(d);
			int action = -1;
			if (numFiles > 0){
				printf("\n==> ATC has detected %d file(s) in the \"To solve\" folder. <==\n\nDo you want to solve the file(s)? (Yes -> 1 / No -> 0)\n", numFiles);
				while (action != 0 && action != 1){
					gets(option);
					action = convertToNumber(option);
					if (action != 0 && action != 1){
						puts("(Yes -> 1 / No -> 0)");
					}
				}
				puts(" ");
			}
			if (action == 1){
				char path[DIM] = "";
				char fileName[DIM] = "";
				int i = 0, j = 0;
				while (numFiles > 0){
					j = 0;
					while (txtFiles[i] != '\n'&&txtFiles[i] != '\0'){
						fileName[j] = txtFiles[i];
						j++; i++;
					}
					fileName[j] = '\0';
					i++;
					numFiles--;
					sprintf(path, "%s%s", directory, fileName);
					processTxt(path, re);
					printf("==> Check the folder \"To solve\" to see the answers file(s) generated. Enter \"to solve\". <== \n\n");
				}
			}
			if (action == 0){
				int disable = -1;
				printf("Do you want to disable the feature? (Yes -> 1 / No -> 0)\n");
				while (disable != 0 && disable != 1){
					gets(option);
					disable = convertToNumber(option);
					if (disable != 0 && disable != 1){
						puts("(Yes -> 1 / No -> 0)");
					}
				}
				puts(" ");
				if (disable == 1){
					FILE *dis = NULL;
					dis = fopen("disable_txt_detector.txt", "w");
					fclose(dis);
					puts("==> To enable the feature later enter \"enable txt detector\" <==\n");
				}

			}
		}
	}
	else{
		fclose(file);
	}
}