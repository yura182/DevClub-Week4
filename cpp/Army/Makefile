CC = g++
# CFLAGS = -g
rwildcard=$(foreach d,$(wildcard $1*), $(call rwildcard,$d/,$2) $(filter $(subst *,%,$2),$d))
SOURCES1 = $(call rwildcard,,*.cpp)
HEADER = $(strip $(HEADER1))
SOURCES = $(strip $(SOURCES1))
OBJ = _obj
OBJECTS = $(SOURCES:%.cpp=$(OBJ)/%.o)
HEADER1 = $(call rwildcard,,*.h)
EXECUTABLE=run
DEP = $(OBJECTS:.o=.d)


all: $(SOURCES) $(EXECUTABLE)
	

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

-include $(DEP)

$(OBJECTS): $(OBJ)/%.o: %.cpp $(OBJ)/%.d
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ $< -c

$(OBJ)/%.d: %.cpp
	@mkdir -p $(@D)
	@$(CPP) $(CFLAGS) $< -MM -MT $(@:%.d=%.o) >$@

.PHONY: clean
clean:
	rm -r -f $(OBJ) $(EXECUTABLE)
# 	rm -f $(DEP)

# .PHONY: cleand
# cleand:
# 	rm -f $(DEP)
