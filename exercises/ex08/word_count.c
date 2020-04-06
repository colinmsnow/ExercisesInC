#include <stdio.h>
#include <stdlib.h>
#include <glib.h>


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
    list = g_strsplit(contents, " ", 2);

    printf("%s", contents);
    printf("%s", list[0]);

    // GHashTable∗ hash = g_hash_table_new(g_str_hash, g_str_equal);


}
