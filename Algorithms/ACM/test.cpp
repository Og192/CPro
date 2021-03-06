
    #include <iostream>  
    #include <stdio.h>  
    using namespace std;  
      
    struct Trade {  
            int javaBean, food;  
            double rate;  
    };  
      
    int main()  
    {  
            const int max = 1001;  
            int catFood, N;  
            int i, j, f, maxIdx;  
            double r, get;  
            Trade record[max], tmp;  
            while (cin >> catFood >> N && (catFood != -1) && (N != -1)) {  
                    i = get = 0;  
                    while (i < N) {  
                            cin >> j >> f;  
                            if (j == 0)  
                                    r = 0.0;  
                            else if (f == 0)  
                                    r = static_cast<double>(max);  
                            else  
                                    r = 1.0 * j/f;  
                            record[i].javaBean = j;  
                            record[i].food = f;  
                            record[i].rate = r;  
                            i++;  
                    }  
      
                    // sort  
                    for (j = 0; j < N - 1; j++) {  
                            // the last one  
                            maxIdx = N - 1;  
                            for (f = j; f < N; f++) {  
                                    if (record[maxIdx].rate < record[f].rate)  
                                            maxIdx = f;  
                            }  
      
                            // swap  
                            tmp = record[j];  
                            record[j] = record[maxIdx];  
                            record[maxIdx] = tmp;  
                    }  
      
                    // mouse will get  
                    for (i = 0; i < N; i++) {  
                            f = record[i].food;  
                            j = record[i].javaBean;  
                            if (catFood >= f) {  
                                    get += j;  
                                    catFood -= f;  
                            } else {  
                                    r = 1.0 * catFood / f;  
                                    get += j * r;  
                                    catFood = 0;  
                            }  
                    }  
                    printf("%0.3f\n", get);  
            }  
      
            return 0;  
    }  
