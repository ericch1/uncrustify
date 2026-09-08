import re
import os

def patch_uncrustify_defaults(filename):
    if not os.path.exists(filename):
        print(f"Erreur : Le fichier '{filename}' est introuvable.")
        return

    with open(filename, 'r', encoding='utf-8') as f:
        content = f.read()

    # 1. Mise à jour des options GLOBALES
    global_patterns = {
        'global_span_num_empty_lines': 'empty lines',
        'global_span_num_pp_lines':    'preprocessor lines',
        'global_span_num_cmt_lines':   'comment lines'
    }

    for opt, label in global_patterns.items():
        pattern = rf"(#.*\n)+{opt}\s*=.*"
        replacement = (
            f"# Maximum budget of {label} to skip for all alignment spans.\n"
            f"#  0: No budget (don't skip any {label}) (default).\n"
            f"# >0: Default budget of {label} to skip between candidates.\n"
            f"{opt:<32} = 0        # unsigned number"
        )
        content = re.sub(pattern, replacement, content)

    # 2. Mise à jour des familles d'options SPÉCIFIQUES
    # Liste précise basée sur tes retours
    families = [
        'var_def', 'var_class', 'var_struct', 'func_proto',
        'func_params', 'typedef', 'assign', 'enum_equ'
    ]
    
    types = {
        'empty': 'empty lines',
        'pp':    'preprocessor lines',
        'cmt':   'comment lines'
    }

    for fam in families:
        for suffix, label in types.items():
            opt_name = f"align_{fam}_span_num_{suffix}_lines"
            # On cherche le bloc de commentaires qui précède l'option
            pattern = rf"(#.*\n)+{opt_name}\s*=.*"
            
            # Nom de la span parente pour la description (ex: align_var_def_span)
            parent_span = f"align_{fam}_span"
            
            replacement = (
                f"# Maximum budget of {label} to skip for {parent_span}.\n"
                f"#  -1: Use the global_span_num_{suffix}_lines budget (default).\n"
                f"#   0: No budget (don't skip any {label}).\n"
                f"#  >0: Skip up to this many {label} between candidates.\n"
                f"{opt_name:<32} = -1       # number"
            )
            content = re.sub(pattern, replacement, content)

    with open(filename, 'w', encoding='utf-8') as f:
        f.write(content)
    print(f"Le fichier {filename} a été mis à jour avec les 8 familles et les options globales.")

if __name__ == "__main__":
    patch_uncrustify_defaults("defaults.cfg")
