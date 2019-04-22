.PHONY: clean All

All:
	@echo "----------Building project:[ UOCCongress - Debug ]----------"
	@cd "UOCCongress" && "$(MAKE)" -f  "UOCCongress.mk"
clean:
	@echo "----------Cleaning project:[ UOCCongress - Debug ]----------"
	@cd "UOCCongress" && "$(MAKE)" -f  "UOCCongress.mk" clean
