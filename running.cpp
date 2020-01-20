#include<unistd.h>
#include<vector>
#include<string.h>
#include<cstring>
#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdlib>
#include<ctime>
#include<sys/time.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<signal.h>

#define KEY_NUM 9527
#define KEY_NUM2 9528
#define KEY_NUM3 9529
#define MEM_SIZE 1024

int shm_id = shmget((key_t)KEY_NUM, MEM_SIZE, IPC_CREAT|0666);
void* shm_addr = shmat(shm_id, (void*)0,0);

int shm_id2 = shmget((key_t)KEY_NUM2, MEM_SIZE, IPC_CREAT|0666);
void* shm_addr2 = shmat(shm_id2, (void*)0,0);

int shm_id3 = shmget((key_t)KEY_NUM3, MEM_SIZE, IPC_CREAT|0666);
void* shm_addr3 = shmat(shm_id3, (void*)0, 0);


using namespace std;

vector<string> common(string s1, string s2, string s3, string s4, string s5)
{
        int i=0;
        int j=0;
        int k=0;
	vector<string> s1v;
        vector<string> s2v;
        vector<string> s3v;
	vector<string> s4v;
	vector<string> s5v;
	vector<string> proposed;
	int count=0;
	string proposedPID;
        string stringBuffer;
        istringstream C1(s1);
        while(getline(C1, stringBuffer, '\n'))
        {
		int i=0;
		s1v.push_back(stringBuffer);
                i++;
        }
        istringstream C2(s2);
        while(getline(C2, stringBuffer, '\n'))
        {
                int j=0;
                s2v.push_back(stringBuffer);
                j++;
        }
        istringstream C3(s3);
        while(getline(C3, stringBuffer, '\n'))
        {
                int k=0;
                s3v.push_back(stringBuffer);
                k++;
        }
	istringstream C4(s4);
	while(getline(C4, stringBuffer, '\n'))
	{
		int k=0;
		s4v.push_back(stringBuffer);
		k++;
	}
	istringstream C5(s5);
	while(getline(C5, stringBuffer, '\n'))
	{
		int k=0;
		s5v.push_back(stringBuffer);
		k++;
	}
	

	for(int i=0; i<s5v.size(); ++i)
        {
		for(int q=0; q<s4v.size(); ++q)
		{	
			if(s5v[i] == s4v[q])
				count++;
		}
		for(int u=0; u<s3v.size(); ++u)
		{
			if(s5v[i] == s3v[u])
				count++;
		}
                for(int j=0; j<s2v.size(); ++j)
                {
                        if(s5v[i] == s2v[j])
                        	count++;
                }
                for(int k=0; k<s1v.size(); ++k)
                {
                        if(s5v[i] == s1v[k])
                                count++;
                }
		if(count == 4)
			proposed.push_back(s5v[i]);

		count = 0;
        }

	/*for(int h=0; h<proposed.size(); ++h)
	{
		proposedPID += s3v[h];
	}*/
	
	return proposed;
	

        /*cout << s1v[0] << " ";
        cout << s1v[1] << " ";
        cout << s1v[2] << " ";
        cout << s2v[0] << " ";
        cout << s2v[1] << " ";
        cout << s3v[0] << " ";
	cout << s3v[1] << " ";*/
	
}
	 

bool issame(vector<string> s1, vector<string> s2)
{
        int count = 0;
        if(s1.size() != s2.size())
                return false;
        else
        {
                for(int i=0; i<s2.size(); i++)
                {
                        for(int j=0; j<s1.size(); j++)
                        {
                                if(s2[i] == s1[j])
                                {
                                        count++;
                                }
                        }
                }
                if(count == s2.size())
                        return true;
                else
                        return false;
        }
}

int stringTOint(string str)
{
	stringstream sstream;
	int num;
	sstream.str(str);
	while(sstream >> num);
	return num;
}

string intTOstring(int n)
{
	stringstream s;
	s << n;
	return s.str();
}
	
int main(int argc, char** argv)
{	
		

	FILE* fp;
	FILE* ff;
	char line[10240];
	string strline="";
	string pid[100];
	string fstpid="";
	string scdpid="";
	string trdpid="";
	string fthpid="";
	string crtpid="";
	int countpast;
	int countnow;
	int breakcount=0;
	int intpid;
	string yesorno="y";
	string stringpid;
	vector<string> stringpids;
	string proposed="";
	vector<string> ardproposed;
	vector<string> proposedPIDs;
	string pausebase = "";
	string killbase = "";
	string restartbase = "";
	string perfbase = "";
	string background = "";

	clock_t start, end;
	double res;

	struct timeval startTime, endTime, gepTime;
	double difftime;

	//int shm_id;
	//void*shm_addr;
	//struct shmid_ds shm_info;

	char attack[10] = "1";
	char attack2[10] = "2";
	char attack3[10] = "3";
	char current[10] ="0";
	

	/*if(-1 == (shm_id = shmget((key_t)KEY_NUM, MEM_SIZE, IPC_CREAT|0666)))
	{
		printf("failed to create shared memory\n");
		return -1;
	}
	if((void*)-1 == (shm_addr = shmat(shm_id, (void*)0, 0)))
	{
		printf("failed to attach shared memory\n");
		return -1;
	}*/

	
	//start = clock();
	gettimeofday(&startTime,NULL);	
	while(1)
	{
		fp = popen("ps aux --no-headers|grep R|grep -v ps|grep -v grep|awk '{print $2}'", "r");
		
		//system("ps aux --no-headers|grep R|grep -v ps|grep -v grep|awk '{print $2}' > output.txt");
		//ifstream inFile("output.txt");
		//string line;
		/*if(!inFile.is_open()){
			cout << "error" << endl;
			break;
		}*/
		if(NULL == fp)
		{
			perror("failed to use popen()\n");
			return -1;
		}
		
		
		fstpid.assign(scdpid);
		scdpid.assign(trdpid);
		trdpid.assign(fthpid);
		fthpid.assign(crtpid);
		crtpid ="";
	
		/*while(getline(fp,line)){	
			crtpid += line;
			crtpid += "\n";	
		
		}*/

		while(fgets(line, 10240, fp) != NULL)
		{
			string strline(line);
			crtpid += strline;
			//crtpid += "\n";
		}


		
		/*cout << "Running processes during the last 5 period" << endl;
		cout << "(1)\n"  <<fstpid;
		cout << "(2)\n" << scdpid;
		cout << "(3)\n" << trdpid;
		cout << "(4)\n" << fthpid;
		cout << "current\n" <<crtpid;
		cout << endl;*/
		
		/*ifstream inFile2("ifattack.txt");
		string line2;
		if(!inFile2.is_open()){
			cout << "error" << endl;
		}
		countpast = countnow;
		countnow = 0;	
		while(getline(inFile2, line2)){
			countnow++;
		}*/
				

		//if (countnow > countpast)
		//strcpy(current, (char*)shm_addr);
		//printf("shared memory read by running : %s\n", (char*)shm_addr);
		if(strcmp(attack,(char*)shm_addr) == 0 || strcmp(attack,(char*)shm_addr2) == 0 || strcmp(attack,(char*)shm_addr3) == 0)
		{	

			if(common(fstpid, scdpid, trdpid, fthpid, crtpid).size() == 0)
			{	
				cout << "-------------------------PCM detected suspicious behaviors, but it's not attack-------------------------" << endl;
			}
			else
			{
				if(strcmp(attack,(char*)shm_addr) == 0)
					cout << "FLUSH+RELOAD ATTACK DETECTED!!!" << endl;
				else if (strcmp(attack,(char*)shm_addr2) == 0)
					cout << "ROW-HAMMERING DETECTED!!!" << endl;
				else if (strcmp(attack,(char*)shm_addr3) == 0)
					cout << "FLUSH+RELOAD ATTACK & ROW-HAMMERING DETECTED!!!" << endl;
				//cout << "Attack Detected!!!" << endl;
				cout << "Potential spy processes : ";
				proposedPIDs = common(fstpid, scdpid, trdpid, fthpid, crtpid);
				for(int i=0; i<proposedPIDs.size(); i++)
				{
					cout << proposedPIDs[i] << " ";
				}
				cout << endl;
	
				if(issame(ardproposed, proposedPIDs))
				{
					ardproposed = proposedPIDs;
					breakcount++;
				}
				else if(!issame(ardproposed, proposedPIDs))
				{
					ardproposed = proposedPIDs;
					breakcount = 0;
				}


				if(breakcount == 4)
				{	
					//end = clock();
					//res = ((double)(end-start));
					gettimeofday(&endTime, NULL);
					difftime = 1000*(endTime.tv_sec - startTime.tv_sec) + ((endTime.tv_usec - startTime.tv_usec)/1000);
					printf("\nTime taken to complete detection : %f milliseconds\n" , difftime);
					system("sudo pkill -9 pcm.x");

					if(-1 == shmdt(shm_addr))
					{
						//printf("failed to detatch shared memory\n");
						return -1;
					}
					else
					{
						//printf("successfully detached shared memory\n");
					}
					shmdt(shm_addr2);
					shmdt(shm_addr3);



                                        if(-1 == shmctl(shm_id, IPC_RMID, 0))
                                        {
                                                //printf("failed to remove shared memory\n");
						return -1;
                                        }
                                        else
                                        {
                                                //printf("successfully removed used shared memory\n");
                                        }
					shmctl(shm_id2, IPC_RMID, 0);
					shmctl(shm_id3, IPC_RMID, 0);

					//cout << "check remaining shared memory  " << (char*)shm_addr << end;



					if (proposedPIDs.size() == 1)
					{
						killbase = "sudo kill -9 ";
						killbase += proposedPIDs[0];
						system(killbase.c_str());	
						cout << "\nSince there was only one potential spy process, so program killed it automatically" << endl;
					}
					else
					{
						for(int i=0; i<proposedPIDs.size(); i++)
						{
							pausebase = "sudo kill -20 ";
							pausebase += proposedPIDs[i];
							system(pausebase.c_str());
						}
						cout << "\nSince there were two or more potential spy processes, program paused those processes" << endl;
						cout << "\nProgram will show you cahe miss status of each PID. Decide spy process and kill it yourself" << endl;

						cout << "\nChecking cache miss status of each PID with perf command......" << endl;

						for(int i=0; i<proposedPIDs.size(); i++)
						{
							cout << "\n[ " << proposedPIDs[i] << "'s cache miss status ]" << endl;
							restartbase = "sudo kill -18 ";
							restartbase += proposedPIDs[i];
							system(restartbase.c_str());

							perfbase = "sudo timeout 0.1s perf stat -I 15 -p ";
							perfbase += proposedPIDs[i];
							perfbase += " -e cache-misses,LLC-loads,LLC-load-misses|awk '{print $1}'";
							system(perfbase.c_str());

							//usleep(1000000);
							system("sudo pkill -2 perf");
							
							pausebase = "sudo kill -20 ";
							pausebase += proposedPIDs[i];
							system(pausebase.c_str());
						
						}

						cout << "\nDid you check cache misses? Which PID will you kill? Input suspicious PID : ";
						while(yesorno == "y" || yesorno == "Y")
						{
							scanf("%d", &intpid);
							stringpid = intTOstring(intpid);
							stringpids.push_back(stringpid);

							//killbase = "sudo kill -9 ";
							//killbase += stringpid;
							//system(killbase.c_str());
							kill(intpid, 9);
	                                                cout << "\nProgram killed " << stringpid << " process " << endl;
	
							cout << "Are there any more suspicious processes? (Y/N) ";
							cin >> yesorno;
							if(yesorno == "n" || yesorno == "N")
								break;	
							cout << "If so, Input suspicious PID : ";
						}
								
						
						if(proposedPIDs.size() == stringpids.size())
							cout << "Since you have killed all processes on the suspect list, there is no innocent process to restart" << endl;
						else if(proposedPIDs.size() >= stringpids.size())
						{
						
							cout << "\nRestarting other innocent processes......" << endl;
	
							for(int i=0; i<proposedPIDs.size(); i++)
							{
								for(int j=0; j<stringpids.size(); j++)
								{
									if(proposedPIDs[i] != stringpids[j])
									{
										restartbase = "sudo kill -18 ";
										restartbase += proposedPIDs[i];
										system(restartbase.c_str());
									}
								}
							}
						
							cout << "\nProgram restarted innocent processes. Do you want to keep them running? (Y/N) ";
							cin >> background;
						
							if(background == "N" || background == "n")
							{
								for(int i=0; i<proposedPIDs.size(); i++)
								{
									for(int j=0; j<stringpids.size(); j++)
									{
        	                       		                        	if(proposedPIDs[i] != stringpids[j])
	                                	                        	{
                	                                                		//killbase = "sudo kill -9 ";
                	                                                		//killbase += proposedPIDs[i];
                	                                                		//system(killbase.c_str());
											kill(stringTOint(proposedPIDs[i]), 9);
                	                                        		}
									}
								}
								cout << "\nProgram has killed the remaining processes at your request" << endl;
							}
						}


					}
					cout << "------------------------------DETECTION COMPLETED------------------------------" << endl;
					system("sudo pkill -9 running");
				}
				//ardproposed = proposedPIDs;
			}
			
			
	
			/*if (proposed == common(trdpid, fthpid, crtpid))
			{	
				breakcount++;
			}	
			if (breakcount==2)
			{
				system("./killer.sh");
			}
			proposed = common(trdpid, fthpid, crtpid);
			*/ //first version : stop detecting when inform only 1 pid
			
			
			/*if (trdpid == fthpid && fthpid == crtpid)
			{
				cout << "potential spy process : "<< crtpid;
				if(proposed == crtpid)
					breakcount++;
				if(breakcount ==2)
					system("./killer.sh");
				proposed = crtpid;
				//breakcount++;
				
			}*/ //no longer used
		}
		//cout << "--------------------------------------------" << endl;
		usleep(15000);
	}
	
	return 0;
}
