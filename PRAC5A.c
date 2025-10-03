#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;
#include &lt;string.h&gt;
#define MAX 100
typedef struct {
    int val;
    char dir;
} Array;
Array c[MAX][MAX];
void LCS(char a[], char b[], int m, int n)
{
    for (int i = 0; i &lt;= m; i++)
    {
        c[i][0].val = 0;
        c[i][0].dir = &#39;H&#39;;
    }
    for (int j = 0; j &lt;= n; j++)
    {
        c[0][j].val = 0;
        c[0][j].dir = &#39;V&#39;;
    }
    for (int i = 1; i &lt;= m; i++)
    {
        for (int j = 1; j &lt;= n; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                c[i][j].val = c[i - 1][j - 1].val + 1;

                c[i][j].dir = &#39;D&#39;;
            }
            else
            {
                if (c[i - 1][j].val &gt;= c[i][j - 1].val)
                {
                    c[i][j].val = c[i - 1][j].val;
                    c[i][j].dir = &#39;U&#39;;
                }
                else
                {
                    c[i][j].val = c[i][j - 1].val;
                    c[i][j].dir = &#39;L&#39;;
                }
            }
        }
    }
}
void Print_LCS(int i, int j, char a[])
{
    if (i == 0 || j == 0)
    {
        return;
    }
    if (c[i][j].dir == &#39;D&#39;)
    {
        Print_LCS(i - 1, j - 1, a);
        printf(&quot;%c&quot;, a[i - 1]);
    }
    else if (c[i][j].dir == &#39;U&#39;)
    {
        Print_LCS(i - 1, j, a);
    }
    else
    {
        Print_LCS(i, j - 1, a);
    }
}
int main() {
    char a[MAX], b[MAX];
    printf(&quot;Enter the first string: &quot;);
    scanf(&quot;%s&quot;, a);
    printf(&quot;Enter the second string: &quot;);
    scanf(&quot;%s&quot;, b);
    int m = strlen(a);
    int n = strlen(b);
    LCS(a, b, m, n);  
    printf(&quot;LCS: &quot;);
    Print_LCS(m, n, a);
    printf(&quot;\n&quot;);

    return 0;
}
