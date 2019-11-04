#include <stdio.h>

int main()
{
    int gols_i, gols_g, z , a=0, g_vit=0, i_vit=0, emp=0, p=0;
        scanf("%d %d", &gols_i, &gols_g);
        p++;
        if(gols_i > gols_g){
            i_vit++;
        }   else if(gols_i < gols_g){
                g_vit++;
        }   else if(gols_i == gols_g){
                emp++;
        }
        while(a<1){
        printf("Novo grenal (1-sim 2-nao)\n");
        scanf("%d", &z);
        switch (z){
            case 1:
                scanf("%d %d", &gols_i, &gols_g);
                p++;
                if(gols_i > gols_g){
                    i_vit++;
                }   else if(gols_i < gols_g){
                        g_vit++;
                }   else if(gols_i == gols_g){
                        emp++;
                }
                break;
            case 2:
                a = 2;
                if(i_vit > g_vit){
                printf("%d grenais\n", p);
                printf("Inter:%d\n", i_vit);
                printf("Gremio:%d\n", g_vit);
                printf("Empates:%d\n", emp);
                printf("Inter venceu mais\n");
                break;
                }   else if(g_vit > i_vit){
                printf("%d grenais\n", p);
                printf("Inter:%d\n", i_vit);
                printf("Gremio:%d\n", g_vit);
                printf("Empates:%d\n", emp);
                printf("Gremio venceu mais\n");
                break;
                }   else if(g_vit == i_vit){
                printf("%d grenais\n", p);
                printf("Inter:%d\n", i_vit);
                printf("Gremio:%d\n", g_vit);
                printf("Empates:%d\n", emp);
                printf("Nao houve vencedor\n");
                break;
        }
    }
}
}