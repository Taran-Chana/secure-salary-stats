/*
Salary: 
	rounded to nearest whole number

Role:
	0: Executives
	1: Management
	2: Software Developer 
	3: Project Manager
	4: HR
	5: Accountant
	6: Sales
	7: Secretary

Gender:
	0: Female
	1: Male
	2: Non-Binary
	3: Other

Ethnicity:
	0: White
	1: Black or African American
	2: American Indian or Alaska Native
	3: Hispanic or Latino
	4: AAPI
	5: South Asian
	6: Other
	7: Two or More Races

Experience:
	years of working experience

*/

//company A
private int A_salary[10];
private int<3> A_role[10];
private int<2> A_gender[10];
private int<3> A_ethnicity[10];
private int A_experience[10];

//company B
private int B_salary[15];
private int<3> B_role[15];
private int<2> B_gender[15];
private int<3> B_ethnicity[15];
private int B_experience[15];

//company C
private int C_salary[15];
private int<3> C_role[15];
private int<2> C_gender[15];
private int<3> C_ethnicity[15];
private int C_experience[15];

//total stats[mean, variance, range]
private int total[3]

//TODO::
//white stats
//NB stats

//generate mean, variance and range of 
void total_stats(){
	private int min, max = A_salary[0];
	private int average = 0;
	private int varience = 0;
	
	//calc total min, max, and mean
	for(int i = 0; i < 10; i++){
		average += A_salary[i];
		if(A_salary[i] < min)
			min = A_salary[i];
		if(A_salary[i] > max)
			max = A_salary[i];
	}
	
	for(int i = 0; i < 15; i++){
		average += B_salary[i];
		if(B_salary[i] < min)
			min = B_salary[i];
		if(B_salary[i] > max)
			max = B_salary[i];
	}
	
	for(int i = 0; i < 15; i++){
		average += C_salary[i];
		if(C_salary[i] < min)
			min = C_salary[i];
		if(C_salary[i] > max)
			max = C_salary[i];
	}
	
	average = average / 40;
	
	//calc variance
	
	for(int i = 0; i < 10; i++){
		variance += (A_salary - average)^2;
	}
	
	for(int i = 0; i < 15; i++){
		variance += (B_salary - average)^2;
	}
	
	for(int i = 0; i < 15; i++){
		variance += (C_salary - average)^2;
	}
	
	total[0] = average;
	total[1] = variance / 39;
	total[2] = max - min;
}

public int main(){
	//a input
	smcinput(A_salary, 1, 10);
	smcinput(A_role, 1, 10);
	smcinput(A_gender, 1, 10);
	smcinput(A_ethnicity, 1, 10);
	smcinput(A_experience, 1, 10);
	
	//b input
	smcinput(B_salary, 1, 15);
	smcinput(B_role, 1, 15);
	smcinput(B_gender, 1, 15);
	smcinput(B_ethnicity, 1, 15);
	smcinput(B_experience, 1, 15);
	
	
	//c input
	smcinput(C_salary, 1, 15);
	smcinput(C_role, 1, 15);
	smcinput(C_gender, 1, 15);
	smcinput(C_ethnicity, 1, 15);
	smcinput(C_experience, 1, 15);
	
	total_stats();
	
	smcoutput(total, 2, 3);

	return 0;
}

