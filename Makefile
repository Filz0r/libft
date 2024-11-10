NAME = libft.a

CC = cc
CFLAGS = -Wall -Werror -Wextra
OBJDIR = build
INCLUDES = include
INCLUDES_FLAGS = -I$(INCLUDES) -I/usr/include
SRC = src

# Tests
TEST_SRC = tests
TEST_OBJDIR = $(OBJDIR)/tests
TEST_FLAGS = -L. -lft -lcmocka -lbsd

SRC_CHAR = char/ft_isalnum.c char/ft_isalpha.c char/ft_isascii.c \
		   char/ft_isdigit.c char/ft_isprint.c char/ft_toupper.c  \
		   char/ft_tolower.c char/ft_iswhitespace.c
SRC_FD = print/ft_putchar_fd.c print/ft_putstr_fd.c print/ft_putnbr_fd.c \
			print/ft_putendl_fd.c
SRC_LISTS = lists/ft_lstadd_back.c lists/ft_lstadd_front.c \
			lists/ft_lstclear.c lists/ft_lstdelone.c \
			lists/ft_lstlast.c lists/ft_lstmap.c lists/ft_lstnew.c \
			lists/ft_lstsize.c lists/ft_lstget.c lists/ft_lstiter.c
SRC_MEM = memory/ft_memchr.c memory/ft_memcmp.c memory/ft_memcpy.c \
			memory/ft_calloc.c memory/ft_memmove.c memory/ft_memset.c \
			memory/ft_realloc.c memory/ft_bzero.c
SRC_NUM = numbers/ft_atoi.c numbers/ft_itoa.c numbers/ft_atol.c
SRC_STR = string/ft_free_split.c string/ft_split.c string/ft_strchr.c \
			string/ft_strdup.c string/ft_striteri.c string/ft_strjoin.c \
			string/ft_strlcat.c string/ft_strlcpy.c string/ft_strlen.c  \
			string/ft_strmapi.c string/ft_strncmp.c string/ft_strnstr.c \
          string/ft_strrchr.c string/ft_strtrim.c string/ft_substr.c \
          string/ft_strclean.c
SRC_PRINTF = printf/ft_printf.c printf/put_utils.c printf/utils.c
SRC_GNL = gnl/get_next_line.c gnl/get_next_line_utils.c gnl/gnl_utils.c
SRC_HASH = hash/ft_hash_add_node.c hash/ft_hash_create_node.c \
			hash/ft_hash_delete.c hash/ft_hash_get_item.c \
			hash/ft_hash_get_node.c hash/ft_hash_new.c hash/ft_hash_print.c \
			hash/ft_hash_remove_node.c hash/hash_utils1.c

SOURCES =	$(addprefix $(SRC)/, $(SRC_GNL)) \
         	$(addprefix $(SRC)/, $(SRC_PRINTF)) \
			$(addprefix $(SRC)/, $(SRC_STR)) \
			$(addprefix $(SRC)/, $(SRC_CHAR)) \
			$(addprefix $(SRC)/, $(SRC_LISTS)) \
			$(addprefix $(SRC)/, $(SRC_MEM)) \
			$(addprefix $(SRC)/, $(SRC_NUM)) \
			$(addprefix $(SRC)/, $(SRC_FD)) \
			$(addprefix $(SRC)/, $(SRC_HASH)) \


OBJECTS =	$(addprefix $(OBJDIR)/, $(SRC_GNL:.c=.o)) \
			$(addprefix $(OBJDIR)/, $(SRC_PRINTF:.c=.o)) \
			$(addprefix $(OBJDIR)/, $(SRC_STR:.c=.o)) \
			$(addprefix $(OBJDIR)/, $(SRC_CHAR:.c=.o)) \
			$(addprefix $(OBJDIR)/, $(SRC_LISTS:.c=.o)) \
			$(addprefix $(OBJDIR)/, $(SRC_MEM:.c=.o)) \
			$(addprefix $(OBJDIR)/, $(SRC_NUM:.c=.o)) \
			$(addprefix $(OBJDIR)/, $(SRC_FD:.c=.o)) \
			$(addprefix $(OBJDIR)/, $(SRC_HASH:.c=.o)) \


# Test files
TEST_FILES = fd.c memory.c strings.c # gnl.c lists.c numbers.c printf.c
TEST_OBJECTS = $(addprefix $(TEST_OBJDIR)/, $(TEST_FILES:.c=.o))
TEST_EXECUTABLES = $(addprefix $(TEST_OBJDIR)/, $(TEST_FILES:.c=.test))

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "Linking Libft"
	@ar rcs $(NAME) $(OBJECTS)
	@echo "Done!"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRC)/%.c
	@mkdir -p $(@D)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES_FLAGS)

clean:
	@rm -rf $(OBJDIR)

debug: CFLAGS += -g3
debug: fclean $(NAME)

fclean: clean
	@rm -f $(NAME)

re: fclean all

# Compile individual test files
$(TEST_OBJDIR)/%.o: $(TEST_SRC)/%.c | $(TEST_OBJDIR)
	@mkdir -p $(@D)
	@echo "Compiling test: $<"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES_FLAGS)

# Create test executables
$(TEST_OBJDIR)/%.test: $(TEST_OBJDIR)/%.o $(NAME)
	@echo "Linking test: $@"
	@$(CC) $< -o $@ $(TEST_FLAGS) $(INCLUDES_FLAGS)

# Individual test targets
test_%: $(NAME) $(TEST_OBJDIR)/%.test
	@echo "Running test: $@"
	@./$(TEST_OBJDIR)/$*.test

# Directory creation
$(TEST_OBJDIR):
	@mkdir -p $(TEST_OBJDIR)

# Run all tests
test: $(TEST_EXECUTABLES)
	@echo "Running all tests..."
	@for test in $(TEST_EXECUTABLES); do \
		echo "Executing $$test:"; \
		./$$test; \
	done

.PHONY: all clean fclean re test debug #$(addprefix test_,$(basename $(TEST_FILES)))
