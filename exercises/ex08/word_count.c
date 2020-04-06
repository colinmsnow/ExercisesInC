#include <stdio.h>
#include <stdlib.h>
#include <glib.h>


void iterator(gpointer key, gpointer value, gpointer user_data) {
//  printf(user_data, *(gint*)key, value);
printf("%s = %d\n", key, value);
}


int main(int argc, char **argv){

    // FILE* file = g_fopen(argv[1], "w");

    const gchar *filename = argv[1];
    gchar *contents;
    GError **error;
    g_file_get_contents (filename,
                     &contents,
                     NULL,
                     error);


    gchar** list = NULL;
    contents = g_ascii_strdown(contents, -1); // makes everything lower case
    list = g_strsplit_set(contents, " .", 0); // Splits words and removes periods

    int current_value;

    GHashTable* dict = g_hash_table_new(g_str_hash, g_str_equal);
    char *current_word;

    int i = 0;
    while (1){
        i +=1 ;
        if (list[i] == NULL){break;}
        current_word = list[i];
         if(g_hash_table_contains(dict, current_word)){
             current_value = g_hash_table_lookup(dict, current_word);
             current_value += 1;
             g_hash_table_replace(dict, current_word, current_value);

         }
         else{
            g_hash_table_insert(dict, current_word, 1);
        }
    }

    g_hash_table_foreach(dict, (GHFunc)iterator, "%s is %d\n");
    


}
