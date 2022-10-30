.PHONY: clean All

All:
	@echo "----------Building project:[ PracticaC1 - Debug ]----------"
	@cd "PracticaC1" && "$(MAKE)" -f  "PracticaC1.mk"
clean:
	@echo "----------Cleaning project:[ PracticaC1 - Debug ]----------"
	@cd "PracticaC1" && "$(MAKE)" -f  "PracticaC1.mk" clean
