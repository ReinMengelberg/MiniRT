** 42 MiniRT project **



valgrind --leak-check=full \
--show-leak-kinds=all \
--track-origins=yes \
--suppressions=minilibx.supp \
./miniRT rtfiles/test4.rt