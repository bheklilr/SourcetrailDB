#ifndef SOURCETRAILDB_H
#define SOURCETRAILDB_H

#include <string>

enum DefinitionKind
{
	DEFINITION_IMPLICIT,
	DEFINITION_EXPLICIT
};

enum SymbolKind
{
	SYMBOL_TYPE,
	SYMBOL_BUILTIN_TYPE,
	SYMBOL_NAMESPACE,
	SYMBOL_PACKAGE,
	SYMBOL_STRUCT,
	SYMBOL_CLASS,
	SYMBOL_INTERFACE,
	SYMBOL_ANNOTATION,
	SYMBOL_GLOBAL_VARIABLE,
	SYMBOL_FIELD,
	SYMBOL_FUNCTION,
	SYMBOL_METHOD,
	SYMBOL_ENUM,
	SYMBOL_ENUM_CONSTANT,
	SYMBOL_TYPEDEF,
	SYMBOL_TEMPLATE_PARAMETER,
	SYMBOL_TYPE_PARAMETER,
	SYMBOL_FILE,
	SYMBOL_MACRO,
	SYMBOL_UNION
};

enum ReferenceKind
{
	REFERENCE_TYPE_USAGE,
	REFERENCE_USAGE,
	REFERENCE_CALL,
	REFERENCE_INHERITANCE,
	REFERENCE_OVERRIDE,
	REFERENCE_TEMPLATE_ARGUMENT,
	REFERENCE_TYPE_ARGUMENT,
	REFERENCE_TEMPLATE_DEFAULT_ARGUMENT,
	REFERENCE_TEMPLATE_SPECIALIZATION,
	REFERENCE_TEMPLATE_MEMBER_SPECIALIZATION,
	REFERENCE_INCLUDE,
	REFERENCE_IMPORT,
	REFERENCE_MACRO_USAGE,
	REFERENCE_ANNOTATION_USAGE
};

int getSupportedDatabaseVersion();

std::string getLastError();

void clearLastError();

bool openProject(std::string projectDirectory, std::string projectName);

bool closeProject();

bool clearProject();

bool isEmpty();

bool isCompatible();

int getLoadedDatabaseVersion();

bool beginTransaction();

bool commitTransaction();

bool rollbackTransaction();

bool optimizeDatabaseMemory();

int recordSymbol(std::string serializedNameHierarchy);

bool recordSymbolDefinitionKind(int symbolId, DefinitionKind symbolDefinitionKind);

bool recordSymbolKind(int symbolId, SymbolKind symbolKind);

bool recordSymbolLocation(int symbolId, std::string filePath, int startLine, int startColumn, int endLine, int endColumn);

bool recordSymbolScopeLocation(int symbolId, std::string filePath, int startLine, int startColumn, int endLine, int endColumn);

bool recordSymbolSignatureLocation(int symbolId, std::string filePath, int startLine, int startColumn, int endLine, int endColumn);

int recordReference(int contextSymbolId, int referencedSymbolId, ReferenceKind referenceKind);

bool recordReferenceLocation(int referenceId, std::string filePath, int startLine, int startColumn, int endLine, int endColumn);

int recordFile(std::string filePath);

int recordLocalSymbol(std::string name);

bool recordLocalSymbolLocation(int localSymbolId, std::string filePath, int startLine, int startColumn, int endLine, int endColumn);

bool recordCommentLocation(std::string filePath, int startLine, int startColumn, int endLine, int endColumn);

bool recordError(std::string message, bool fatal, std::string filePath, int startLine, int startColumn, int endLine, int endColumn);

#endif // SOURCETRAILDB_H